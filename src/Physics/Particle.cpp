#include "Particle.h"

Particle::Particle(float x, float y, float mass) {
  position = Vector2(x, y);

  this->velocity = Vector2(0, 0);
  this->acceleration = Vector2(0, 0);
  this->mass = mass;

  if (mass != 0)
    this->invMass = 1.0 / mass;
  else
    this->invMass = 0;
}

bool Particle::IsStatic() const {
  const float epsilon = 0.005f;
  return fabs(invMass - 0.0) < epsilon;
}

void Particle::AddForce(const Vector2 &force) { forceAccumulator += force; }

void Particle::Integrate(float dt) {
  if (IsStatic())
    return;

  // EULER Integration
  acceleration = forceAccumulator * dt;
  velocity += acceleration * dt;
  position += velocity * dt;

  forceAccumulator = Vector2(0, 0);
}
