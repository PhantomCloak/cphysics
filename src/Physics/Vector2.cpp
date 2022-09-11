#include "Vector2.h"

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(float x, float y) {
  this->x = x;
  this->y = y;
}

float Vector2::Magnitude() const { return sqrt(x * x + y * y); }

Vector2 &Vector2::Normalize() {
  float len = Magnitude();
  if (len != 0) {
    x /= len;
    y /= len;
  }
  return *this;
}

Vector2 Vector2::UnitVector() const {
  Vector2 result = Vector2(0, 0);
  float len = Magnitude();
  if (len != 0) {
    result.x = x / len;
    result.y = y / len;
  }

  return result;
}

float Vector2::Dot(const Vector2 &v) const { return (x * v.x) + (y * v.y); }

float Vector2::Cross(const Vector2 &v) const { return (x * v.y) + (y * v.x); }

Vector2 &Vector2::operator=(const Vector2 &v) {
  x = v.x;
  y = v.y;
  return *this;
}

bool Vector2::operator==(const Vector2 &v) const {
  return x == v.x && y == v.y;
}

bool Vector2::operator!=(const Vector2 &v) const { return !(*this == v); }

Vector2 Vector2::operator+(const Vector2 &v) const {
  Vector2 result;
  result.x = x + v.x;
  result.x = y + v.y;
  return result;
}

Vector2 Vector2::operator-(const Vector2 &v) const {
  Vector2 result;
  result.x = x - v.x;
  result.x = y - v.y;
  return result;
}

Vector2 Vector2::operator*(const float n) const {
  Vector2 result;
  result.x = x * n;
  result.x = y * n;
  return result;
}

Vector2 Vector2::operator/(const float n) const {
  Vector2 result;
  result.x = x / n;
  result.x = y / n;
  return result;
}

Vector2 &Vector2::operator+=(const Vector2 &v) {
  x += v.x;
  y += v.y;
  return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &v) {
  x -= v.x;
  y -= v.y;
  return *this;
}

Vector2 &Vector2::operator*=(const float n) {
  x *= n;
  y *= n;
  return *this;
}

Vector2 &Vector2::operator/=(const float n) {
  x /= n;
  y /= n;
  return *this;
}

Vector2 Vector2::operator-() {
  Vector2 result;
  result.x = x * -1;
  result.y = y * -1;
  return *this;
}
