#include "gridmachine.ih"

unsigned short GridMachine::cell(Point2D point)
{
  return *(this->cellReference(point));
}
