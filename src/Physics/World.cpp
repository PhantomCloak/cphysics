#include "World.h"

World::World(float g) { gravity = -g; }
World::~World() {}

void World::AddParticle(Particle *particle) { particles.push_back(particle); }
void World::AddCircle(Circle *particle) { circles.push_back(particle); }

void World::AddForce(const Vector2 &force) {}
void World::AddTorque(const Vector2 &force) {}

std::vector<Particle *> &World::GetParticles() { return particles; }
std::vector<Circle *> &World::GetCircles() { return circles; }

void World::Update(float dt) {

  // Add all forces
  const Vector2 gravityForce = Vector2(0, gravity * SCREEN_FORCE_MULTIPLIER);

  for (auto particle : particles) {
    particle->AddForce(gravityForce);
  }

  for (auto circle : circles) {
    // circle->AddForce(gravityForce);
  }

  // Integrate all forces
  for (auto particle : particles) {
    particle->Integrate(dt);
  }
  for (auto circle : circles) {
    circle->Integrate(dt);
  }
}

void World::CheckCollisions() {}
