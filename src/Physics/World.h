#ifndef WORLD_H
#define WORLD_H

#include "Vector2.h"
#include <vector>

class World {
private:
  float gravity = -9.8;
  std::vector<float> torques;

public:
  World(float gravity);
  ~World();

  void AddForce(const Vector2 &force);
  void AddTorque(const Vector2 &force);

  void Update(float dt);
  void CheckCollisions();
};

#endif // !WORLD_H
