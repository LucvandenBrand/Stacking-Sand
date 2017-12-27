#include "tetrismachine.ih"

void TetrisMachine::step()
{
  Grid* currentGrid = this->d_grid;

  for (short posY = currentGrid->height()-1; posY > -1; --posY)
  {
    // Move cells down and count the amount of cells in one row.
    unsigned short cellCount = 0;
    for (unsigned short posX = 0; posX < currentGrid->width(); ++posX)
    {
      Point2D currentPoint(posX, posY);
      unsigned short* cell      = currentGrid->cell(currentPoint);
      Point2D belowPoint(posX, posY+1);
      unsigned short* cellBelow = currentGrid->cell(belowPoint);

      /* Check whether there is a zero value at (posX, posY+1),
       * and if posY < height. If so, swap cells (move cell down). */
      if (belowPoint.y < currentGrid->height() && *cellBelow == 0)
      {
        unsigned short temp = *cell;
        *cell      = *cellBelow;
        *cellBelow = temp;
      }
      else if (*cell > 0)
        ++cellCount;
    }

    // If the entire row is stationary cells, decrease their value.
    if (cellCount == currentGrid->width())
      for (unsigned short posX = 0; posX < currentGrid->width(); ++posX)
      {
        unsigned short* cell = currentGrid->cell(Point2D(posX, posY));
        --*(cell);
        if (*cell == 0) // Cell destroyed, increase score.
          ++this->d_score;
      }
  }
}
