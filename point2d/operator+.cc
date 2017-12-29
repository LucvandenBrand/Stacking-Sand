#include "point2d.ih"

const Point2D Point2D::operator+(const Point2D &other) const {
  Point2D result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
  result += other;            // Use += to add other to the copy.
  return result;              // All done!
}
