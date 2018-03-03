#include "grid.ih"

unsigned short Grid::cell(Point2D point)
{
  // Wrap around position indexes;
  point.x %= d_width;
  point.y %= d_height;

  return d_cells[project2D(point, d_width)];
}
