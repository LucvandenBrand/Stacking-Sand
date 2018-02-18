#include "point2d.ih"

Point2D& Point2D::operator+=(const Point2D &other)
{
   this->x += other.x;
   this->y += other.y;
   return *this;
 }
