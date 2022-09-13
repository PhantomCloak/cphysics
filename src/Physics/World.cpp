#include "World.h"

World::World(float g) { gravity = -g; }

void World::AddParticle(Particle *particle) { particles.push_back(particle); }

void World::AddForce(const Vector2 &force) {}

void World::AddTorque(const Vector2 &force) {}

std::vector<Particle *> &World::GetParticles() { return particles; }

void World::Update(float dt) {

  // Add all forces
  const Vector2 gravityForce = Vector2(0, gravity);

  for (auto particle : particles) {
    particle->AddForce(gravityForce);
  }

  // Integrate all forces
  for (auto particle : particles) {
    if (particle->mass != 0)
      particle->Integrate(dt);
  }
}

void World::CheckCollisions() {}
