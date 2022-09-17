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

  // Gravity
  for (auto circle : circles) {
    circle->AddForce(gravityForce);
    circle->isCollide = false;
  }

  // Collisions
  for (auto circle : circles) {
    circle->Integrate(dt);
  }

  for (auto circle : circles) {
    circle->forceAccumulator = Vector2(0, 0);
  }

  if (circles.size() != 0)
    for (int i = 0; i <= circles.size() - 1; i++) {
      for (int j = i + 1; j < circles.size(); j++) {
        Circle *a = circles[i];
        Circle *b = circles[j];
        CircleContactInfo contact;
        if (CollisionDetection::IsCollidingCircles(a, b, contact)) {
          a->isCollide = true;
          b->isCollide = true;
          contact.ResolvePenetration();
        }
      }
    }
}

void World::CheckCollisions() {}
