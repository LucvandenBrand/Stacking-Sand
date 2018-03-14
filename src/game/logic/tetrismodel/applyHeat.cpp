#include "tetrismodel.ih"

void TetrisModel::applyHeat(Point2D point)
{
  /* Check the environment. */
  Point2D up    = point + Point2D( 0,  1);
  Point2D down  = point + Point2D( 0, -1);
  Point2D right = point + Point2D( 1,  0);
  Point2D left  = point + Point2D(-1,  0);

  int upCell = 0;
  if (up.y < d_grid.height())
    upCell = d_grid.cell(up);

  int downCell = 0;
  if (down.y >= 0)
    downCell = d_grid.cell(down);

  int rightCell = 0;
  if (right.x < d_grid.width())
    rightCell = d_grid.cell(right);

  int leftCell = 0;
  if (left.x >= 0)
    leftCell = d_grid.cell(left);

  // Check the heat of the environment.
  int heat = 0;
  if (upCell    > 0)
    heat += HEAT[upCell-1];
  if (downCell  > 0)
    heat += HEAT[downCell-1];
  if (rightCell > 0)
    heat += HEAT[rightCell-1];
  if (leftCell  > 0)
    heat += HEAT[leftCell-1];

  // Apply heat to the current point.
  unsigned short cell = d_grid.cell(point);
  if (cell == SAND  && heat >= HEAT_SAND_TO_GLASS)
    d_grid.cell(point, GLASS);
  if (cell == COAL  && heat >= HEAT_COAL_TO_COAL_FIRE)
    d_grid.cell(point, COAL_FIRE);
}