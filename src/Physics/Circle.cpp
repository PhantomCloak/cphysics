#include "Circle.h"

Circle::Circle(float x, float y, float radius, float mass) {
  this->position.x = x;
  this->position.y = y;
  this->radius = radius;
  this->rotation = 0;
  this->mass = mass;
}

Circle::~Circle() {}

void Circle::AddForce(const Vector2 &force) { forceAccumulator += force; }
void Circle::AddTorque(const float torque) { torqueAccumulator += torque; }

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
