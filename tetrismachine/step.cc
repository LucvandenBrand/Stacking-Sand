#include "tetrismachine.ih"

void TetrisMachine::step()
{
  Grid* currentGrid = this->d_grid;

  for (short posY = currentGrid->height()-1; posY > -1; --posY)
  {
    // Move cells down and count the amount of stationary cells in one row.
    unsigned short rowCount = 0;
    for (unsigned short posX = 0; posX < currentGrid->width(); ++posX)
    {
      Point2D currentPoint(posX, posY);
      unsigned short* cell = currentGrid->cell(currentPoint);

      if (*cell == 0) // Empty cell, do nothing.
        continue;

      /* Check whether there is a zero value at (posX, posY+1),
       * and if posY < height. If so, swap cells (move cell down). */
      Point2D belowPoint(posX, posY+1);
      unsigned short* cellBelow = currentGrid->cell(belowPoint);

      if (belowPoint.y < currentGrid->height() && *cellBelow == 0)
      {
        unsigned short temp = *cell;
        *cell      = *cellBelow;
        *cellBelow = temp;
      }
      else // We are stationary, count the cells on top.
      {
        applyPressure(currentPoint);
        ++rowCount;
      }
    }

    // If the entire row is stationary cells, destroy them and count the score.
    if (rowCount == currentGrid->width())
      for (unsigned short posX = 0; posX < currentGrid->width(); ++posX)
      {
        unsigned short* cell = currentGrid->cell(Point2D(posX, posY));
        this->d_score += *cell;
        *cell = 0;
      }
  }
}
