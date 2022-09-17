#include "CollisionInfo.h"

void CircleContactInfo::ResolveCollision() {
  if (circleA->IsStatic() && circleB->IsStatic()) {
    return;
  }

  float da = depth / (circleA->invMass + circleB->invMass) * circleA->invMass;
  float db = depth / (circleA->invMass + circleB->invMass) * circleB->invMass;

  circleA->position -= normal * da;
  circleB->position += normal * db;
}

void CircleContactInfo::ResolvePenetration() {
  ResolveCollision();

  // Define elasticity (coefficient of restitution e)
  float e = 1; // Calculate the relative velocity between the two objects
  const Vector2 vrel = (circleA->velocity - circleB->velocity);

  // Calculate the relative velocity along the normal collision vector
  float vrelDotNormal = vrel.Dot(normal);

  // Now we proceed to calculate the collision impulse
  const Vector2 impulseDirection = normal;
  const float impulseMagnitude =
      -(1 + e) * vrelDotNormal / (circleA->invMass + circleB->invMass);

  Vector2 jn = impulseDirection * impulseMagnitude;

  // Apply the impulse vector to both objects in opposite direction
  Vector2 a = jn;
  circleA->ApplyImpulse(a);
  Vector2 b = -jn;
  circleB->ApplyImpulse(b);
}
