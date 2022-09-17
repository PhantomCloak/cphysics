#include "Circle.h"
#include <cstdio>

Circle::Circle(float x, float y, float radius, float mass) {
  this->position.x = x;
  this->position.y = y;
  this->radius = radius;
  this->rotation = 0;
  this->torqueAccumulator = 0;
  this->angularAcceleration = 0;
  this->angularVelocity = 0;
  this->intertia = GetIntertia();
  this->isCollide = false;

  if (intertia != 0)
    this->invIntertia = 1.0f / this->intertia;
  else
    this->invIntertia = 0;

  this->mass = mass;
  if (mass != 0) {
    this->invMass = 1.0f / mass;
  }
}

Circle::~Circle() {}

void Circle::AddForce(const Vector2 &force) { forceAccumulator += force; }
void Circle::AddTorque(const float torque) { torqueAccumulator += torque; }
void Circle::ApplyImpulse(const Vector2 &impulse) {
  if (IsStatic())
    return;
  velocity += impulse * invMass;
}

float Circle::GetIntertia() const { return 0.5f * (radius * radius); }

bool Circle::IsStatic() const {
  const float epsilon = 0.005f;
  return fabs(invMass - 0.0) < epsilon;
}

void Circle::Integrate(float dt) {
  if (IsStatic())
    return;

  // EULER Integration
  acceleration = forceAccumulator * invMass;
  velocity += acceleration * dt;
  position += velocity * dt;

  angularAcceleration = torqueAccumulator * invIntertia;

  angularVelocity += angularAcceleration * dt;
  rotation += angularVelocity * dt;

  torqueAccumulator = 0;
  forceAccumulator = Vector2(0, 0);
}
