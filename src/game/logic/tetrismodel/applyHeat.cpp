#include "tetrismodel.ih"

void TetrisModel::applyHeat(Point2D point)
{
  // Check the environment.
  Point2D up    = point + Point2D( 0,  1);
  Point2D down  = point + Point2D( 0, -1);
  Point2D right = point + Point2D( 1,  0);
  Point2D left  = point + Point2D(-1,  0);

  Grid currentGrid = d_grid;

  int upCell = 0;
  if (up.y < currentGrid.height())
    upCell = currentGrid.cell(up);

  int downCell = 0;
  if (down.y >= 0)
    downCell = currentGrid.cell(down);

  int rightCell = 0;
  if (right.x < currentGrid.width())
    rightCell = currentGrid.cell(right);

  int leftCell = 0;
  if (left.x >= 0)
    leftCell = currentGrid.cell(left);

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
  if (cell == ICE && heat >= HEAT_ICE_TO_PLANT)
    d_grid.cell(point, PLANT);
  if (cell == COAL_FIRE && heat <= HEAT_LAVA_TO_STONE)
    d_grid.cell(point, COAL);
  if (cell == LAVA && heat <= HEAT_LAVA_TO_STONE)
    d_grid.cell(point, STONE);
}