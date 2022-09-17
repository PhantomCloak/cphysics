#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include "Circle.h"
#include "CollisionInfo.h"

struct CollisionDetection {
  static bool IsCollidingCircles(Circle *a, Circle *b, CircleContactInfo &c);
};
#endif // !COLLISION_DETECTION_H
