#include "tetrisgrid.ih"

void TetrisGrid::swapCells(Point2D point1, Point2D point2)
{
  unsigned short cell1 = cell(point1);
  unsigned short cell2 = cell(point2);
  cell(point1, cell2);
  cell(point2, cell1);
}
