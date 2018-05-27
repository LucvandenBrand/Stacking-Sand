#include "point2d.ih"

const Point2D Point2D::operator*(const int &other) const {
  Point2D result = *this;
  result.x *= other;
  result.y *= other;
  return result;
}
