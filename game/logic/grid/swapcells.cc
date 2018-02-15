#include "grid.ih"

void Grid::swapCells(Point2D fromCell, Point2D toCell)
{
  unsigned short fromCellValue = this->cell(fromCell);
  this->cell(fromCell, this->cell(toCell));
  this->cell(toCell, fromCellValue);
}
