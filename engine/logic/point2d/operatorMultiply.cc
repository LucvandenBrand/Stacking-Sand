#include "point2d.ih"

const Point2D Point2D::operator*(const int &other) const {
  Point2D result = *this;     // Make a copy of myself.
  result.x *= other;
  result.y *= other;
  return result;
}
