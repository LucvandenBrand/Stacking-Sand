#include "grid.ih"

void Grid::cell(Point2D point, unsigned short value)
{
  // Wrap around position indexes;
  point.x %= this->d_width;
  point.y %= this->d_height;

  this->d_cells[project2D(point, this->d_width)] = value;
}
