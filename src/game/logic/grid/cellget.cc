#include "grid.ih"

unsigned short Grid::cell(Point2D point)
{
  // Wrap around position indexes;
  point.x %= this->d_width;
  point.y %= this->d_height;

  return this->d_cells[project2D(point, this->d_width)];
}
