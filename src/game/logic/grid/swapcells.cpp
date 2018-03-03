#include "grid.ih"

void Grid::swapCells(Point2D fromCell, Point2D toCell)
{
  unsigned short fromCellValue = cell(fromCell);
  cell(fromCell, cell(toCell));
  cell(toCell, fromCellValue);
}
