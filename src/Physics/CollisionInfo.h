#ifndef CONTACT_H
#define CONTACT_H

#include "Circle.h"
#include "math.h"
struct CircleContactInfo {
  Circle *circleA;
  Circle *circleB;

  Vector2 start;
  Vector2 end;

  Vector2 normal;
  float depth;

  void ResolvePenetration();
  void ResolveCollision();
};

#endif
