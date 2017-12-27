#include "gridmachine.ih"

unsigned short* GridMachine::cellReference(Point2D point)
{
  // Wrap around position indexes;
  point.x(point.x() % this->d_width);
  point.y(point.y() % this->d_height);

  return &(this->d_cells[project2D(point, this->d_width)]);
}
