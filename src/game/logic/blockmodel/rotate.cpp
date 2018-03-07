#include "blockmodel.ih"

void BlockModel::rotate()
{
  Grid fromBlock = currentBlock();
  unsigned short width = fromBlock.width();
  unsigned short height = fromBlock.height();
  Grid rotateBlock(height, width);
  for (short y = 0; y < height; y++)
    for (short x = 0; x < width; x++)
    {
      Point2D fromPoint(x, y);
      Point2D toPoint(height-y-1,x);
      rotateBlock.cell(toPoint, fromBlock.cell(fromPoint));
    }
  d_currentBlock = rotateBlock;
  if (overlap(position()))
    d_currentBlock = fromBlock;
}