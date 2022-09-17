#include "CollisionDetection.h"

bool CollisionDetection::IsCollidingCircles(Circle *circleA, Circle *circleB,
                                            CircleContactInfo &contact) {
  const Vector2 ab = circleB->position - circleA->position;
  const float radiusSum = circleA->radius + circleB->radius;

  bool isColliding = ab.MaginitudeSquared() <= (radiusSum * radiusSum);

  if (!isColliding)
    return false;

  contact.circleA = circleA;
  contact.circleB = circleB;

  contact.normal = ab;
  contact.normal.ToUnitVector();

  contact.start = circleB->position - contact.normal * circleB->radius;
  contact.end = circleA->position + contact.normal * circleA->radius;

  contact.depth = (contact.end - contact.start).Magnitude();

  return true;
}
