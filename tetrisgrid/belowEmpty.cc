#include "tetrisgrid.ih"

bool TetrisGrid::belowEmpty(Point2D point)
{
  point.y(point.y() + 1);
  return (point.y() < height()) && (cell(point) == 0);
}
