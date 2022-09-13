#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector2.h"

struct Particle {
  Vector2 position;
  Vector2 velocity;
  Vector2 acceleration;

  Vector2 forceAccumulator;

  float mass;
  float invMass;

  Particle(float x, float y, float mass);
  ~Particle();

  void AddForce(const Vector2 &force);
  void Integrate(float dt);
  bool IsStatic() const;
};

#endif // !PARTICLE_H
