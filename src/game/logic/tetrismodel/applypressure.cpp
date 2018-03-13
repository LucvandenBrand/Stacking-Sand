#include "tetrismodel.ih"

void TetrisModel::applyPressure(Point2D point) {
  /* Count the mass on top. */
  short topMass = 0;
  for (int y = 0; y < point.y; ++y) {
    topMass += d_grid.cell(Point2D(point.x, y));
  }

  unsigned short cell = d_grid.cell(point);
  if (cell == SAND  && topMass >= PRESSURE_STONE)
    d_grid.cell(point, STONE);
  if (cell == STONE && topMass >= PRESSURE_DIAMOND)
    d_grid.cell(point, DIAMOND);
  if (cell == PLANT && topMass >= PRESSURE_COAL)
      d_grid.cell(point, COAL);
}
