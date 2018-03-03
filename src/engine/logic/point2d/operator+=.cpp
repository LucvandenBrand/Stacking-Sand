#include "point2d.ih"

Point2D& Point2D::operator+=(const Point2D &other)
{
   x += other.x;
   y += other.y;
   return *this;
 }
