#ifndef CIRCLE_H
#define CIRCLE_H

#include "Vector2.h"

class Circle {
public:
  Vector2 position;
  Vector2 velocity;
  Vector2 acceleration;

  Vector2 forceAccumulator;
  float torqueAccumulator;

  float rotation;
  float angularVelocity;
  float angularAcceleration;

  float mass;
  float invMass;

  float intertia;
  float invIntertia;

  float radius;
  bool isCollide;

  Circle(float x, float y, float radius, float mass);
  ~Circle();

  void AddForce(const Vector2 &force);
  void AddTorque(const float torque);
  void ApplyImpulse(const Vector2 &impulse);

  void Integrate(float dt);
  float GetIntertia() const;
  bool IsStatic() const;
};

#endif
