#include "tetrismodel.ih"

void TetrisModel::step(float deltaTime)
{
  if (this->paused()) // If the object is paused, do nothing.
    return;

  if (this->d_timeToWait > 0) // We still have time left, so we do nothing.
  {
    this->d_timeToWait -= deltaTime;
    return;
  }

  // Time to wait is over, we reset the timer based on the current score.
  this->d_timeToWait = this->waitTime();

  for (int posY = d_grid.height()-1; posY > -1; --posY)
  {
    // Move cells down and count the amount of stationary cells in one row.
    unsigned short rowCount = 0;
    for (unsigned short posX = 0; posX < d_grid.width(); ++posX)
    {
      Point2D currentPoint(posX, posY);
      unsigned short cell = d_grid.cell(currentPoint);

      if (cell == 0) // Empty cell, do nothing.
        continue;

      /* Check whether there is a zero value at (posX, posY+1),
       * and if posY < height. If so, swap cells (move cell down). */
      Point2D belowPoint(posX, posY+1);
      unsigned short cellBelow = d_grid.cell(belowPoint);

      if (belowPoint.y < d_grid.height() && cellBelow == 0)
        d_grid.swapCells(currentPoint, belowPoint);
      else // We are stationary, count the cells on top.
      {
        applyPressure(currentPoint);
        ++rowCount;
      }
    }

    // If the entire row is stationary cells, destroy them and count the score.
    if (rowCount == d_grid.width())
      for (unsigned short posX = 0; posX < d_grid.width(); ++posX)
      {
        Point2D currentPoint(posX, posY);
        unsigned short cell = d_grid.cell(currentPoint);
        this->d_score += cell;
        d_grid.cell(currentPoint, 0);
      }
  }
}
