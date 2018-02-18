#include "grid.ih"

unsigned short Grid::project2D(Point2D point, unsigned short width) const
{
  return point.y * width + point.x;
}
