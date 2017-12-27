#include "gridmachine.ih"

void GridMachine::cell(Point2D point, unsigned short value)
{
  *(this->cellReference(point)) = value;
}
