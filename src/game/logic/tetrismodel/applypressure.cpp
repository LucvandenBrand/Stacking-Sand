#include "tetrismodel.ih"

void TetrisModel::applyPressure(Point2D point) {
  /* Count the mass on top. */
  short topMass = 0;
  for (int y = 0; y < point.y; ++y) {
    int cell = d_grid.cell(Point2D(point.x, y));
    if (cell != 0)
      topMass += WEIGHT[d_grid.cell(Point2D(point.x, y))-1];
  }

  unsigned short cell = d_grid.cell(point);
  if (cell == SAND  && topMass >= PRESSURE_SAND_TO_STONE)
    d_grid.cell(point, STONE);
  if (cell == PLANT && topMass >= PRESSURE_PLANT_TO_COAL)
      d_grid.cell(point, COAL);
  if (cell == COAL && topMass >= PRESSURE_COAL_TO_DIAMOND)
    d_grid.cell(point, DIAMOND);
  if (cell == GLASS && topMass >= PRESSURE_GLASS_TO_AIR)
    d_grid.cell(point, AIR);
}
