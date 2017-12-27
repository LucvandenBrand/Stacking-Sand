#include "tetrisgrid.ih"

void TetrisGrid::updateGrid()
{
  for (short posY = height()-1; posY > -1; --posY)
  {
    // Move cells down and count the amount of cells in one row.
    unsigned short cellCount = 0;
    for (unsigned short posX = 0; posX < width(); ++posX)
    {
      Point2D currentPoint(posX, posY);
      if (belowEmpty(currentPoint))
        swapCells(currentPoint, Point2D(posX, posY+1));
      else if (cell(currentPoint) > 0)
        ++cellCount;
    }

    // If the entire row is stationary cells, decrease their value.
    if (cellCount == width())
      for (unsigned short posX = 0; posX < width(); ++posX)
      {
        unsigned short* cell = cellReference(Point2D(posX, posY));
        --*(cell);
        if (*cell == 0) // Cell destroyed, increase score.
          ++this->d_score;
      }
  }
}
