#include "blockmodel.ih"

bool BlockModel::overlap(Point2D newPosition)
{
  // Get the current block and grid in use.
  Grid block = this->d_blocks[this->d_currentBlockIndex];
  Grid grid  = *(this->d_tetrisGrid);

  // Determine block bottom and right side.
  unsigned short bottomSide = newPosition.y + block.height();
  unsigned short rightSide  = newPosition.x + block.width();

  // First check if the block is between boundaries.
  bool outBoundaries =  (newPosition.y < 0) || (bottomSide > grid.height())
                     || (newPosition.x < 0) || (rightSide > grid.width());
  if(outBoundaries)
    return true;

  // Check if the block is not overlapping anything.
  for (unsigned short posY = 0; posY < block.height(); ++posY)
  {
    for (unsigned short posX = 0; posX < block.width(); ++posX)
    {
      Point2D cellPosition     = Point2D(posX, posY);
      unsigned short blockCell = *(block.cell(cellPosition));
      Point2D stampPosition    = newPosition + cellPosition;
      unsigned short gridCell  = *(grid.cell(stampPosition));
      if (blockCell && gridCell)
        return true;
    }
  }

  return false;
}
