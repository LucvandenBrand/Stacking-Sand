#include "grid.ih"

void Grid::cell(Point2D point, unsigned short value)
{
  // Wrap around position indexes;
  point.x %= d_width;
  point.y %= d_height;

  d_cells[project2D(point, d_width)] = value;
}
