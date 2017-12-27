#include "gridmachine.ih"

unsigned short GridMachine::project2D(Point2D point, unsigned short width) const
{
  return point.y() * width + point.x();
}
