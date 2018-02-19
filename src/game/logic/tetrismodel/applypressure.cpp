#include "tetrismodel.ih"

void TetrisModel::applyPressure(Point2D point)
{
  /* Count the mass on top. */
  short topMass = 0;
  for (int y = 0; y < point.y; ++y)
  {
    topMass += d_grid->cell(Point2D(point.x, y));
  }

  if (topMass >= PRESSURE_DIAMOND)
    d_grid->cell(point, DIAMOND);
  else if (topMass >= PRESSURE_STONE)
    d_grid->cell(point, STONE);
}
