#include "blockmodel.ih"

Grid BlockModel::rotateGrid(Grid grid)
{
  unsigned short width = grid.width();
  unsigned short height = grid.height();
  Grid rotatedGrid(height, width);
  for (short y = 0; y < height; y++)
    for (short x = 0; x < width; x++)
    {
      Point2D fromPoint(x, y);
      Point2D toPoint(height-y-1,x);
      rotatedGrid.cell(toPoint, grid.cell(fromPoint));
    }
  d_currentBlock = rotatedGrid;
  if (overlap(position()))
    d_currentBlock = grid;
  return d_currentBlock;
}