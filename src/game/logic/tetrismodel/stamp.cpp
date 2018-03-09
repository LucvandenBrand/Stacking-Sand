#include "tetrismodel.ih"

void TetrisModel::stamp(Grid fromGrid, Point2D position)
{
  for (unsigned short posY = 0; posY < fromGrid.height(); ++posY)
  {
    for (unsigned short posX = 0; posX < fromGrid.width(); ++posX)
    {
      Point2D cellPosition = Point2D(posX, posY);
      unsigned short cell = fromGrid.cell(cellPosition);
      if (cell == 0) // Empty cells are not copied to d_grid.
        continue;
      Point2D stampPosition = position + cellPosition;
      d_grid.cell(stampPosition, cell);
    }
  }
}
