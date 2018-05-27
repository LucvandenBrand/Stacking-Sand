#include "point2d.ih"

const Point2D Point2D::operator+(const Point2D &other) const {
  Point2D result = *this;
  result += other;
  return result;
}
