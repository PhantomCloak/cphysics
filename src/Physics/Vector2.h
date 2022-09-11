#ifndef VECTOR2
#define VECTOR2

#include "math.h"
struct Vector2 {

  float x;
  float y;
  Vector2();
  Vector2(float x, float y);
  ~Vector2() = default;

  float Magnitude() const;
  float MaginitudeSquared() const;

  Vector2 &Normalize();
  Vector2 UnitVector() const;

  float Dot(const Vector2 &v) const;
  float Cross(const Vector2 &v) const;

  Vector2 &operator=(const Vector2 &v);
  bool operator==(const Vector2 &v) const;
  bool operator!=(const Vector2 &v) const;

  Vector2 operator+(const Vector2 &v) const;
  Vector2 operator-(const Vector2 &v) const;
  Vector2 operator*(const float n) const;
  Vector2 operator/(const float n) const;
  Vector2 operator-();

  Vector2 &operator+=(const Vector2 &v);
  Vector2 &operator-=(const Vector2 &v);
  Vector2 &operator*=(const float n);
  Vector2 &operator/=(const float n);
};
#endif
