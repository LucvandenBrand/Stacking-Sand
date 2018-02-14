#include "blockmodel.ih"

void BlockModel::stamp()
{
  Grid currentBlock =  this->d_blocks[this->d_currentBlockIndex];
  for (unsigned short posY = 0; posY < currentBlock.height(); ++posY)
  {
    for (unsigned short posX = 0; posX < currentBlock.width(); ++posX)
    {
      Point2D cellPosition = Point2D(posX, posY);
      unsigned short cell = *(currentBlock.cell(cellPosition));
      Point2D stampPosition = this->d_position + cellPosition;
      *(this->d_tetrisGrid->cell(stampPosition)) = cell;
    }
  }
}
