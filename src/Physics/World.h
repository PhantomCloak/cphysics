#ifndef WORLD_H
#define WORLD_H

#include "Particle.h"
#include "Vector2.h"
#include <vector>

class World {
private:
  float gravity = -9.8;
  std::vector<float> torques;
  std::vector<Particle *> particles;

public:
  World(float g);
  ~World();

  void AddParticle(Particle *p);

  void AddForce(const Vector2 &force);
  void AddTorque(const Vector2 &force);

  std::vector<Particle *> &GetParticles();

  void Update(float dt);
  void CheckCollisions();
};

#endif // !WORLD_H
