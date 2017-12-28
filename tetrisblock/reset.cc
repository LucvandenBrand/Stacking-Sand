#include "tetrisblock.ih"

void TetrisBlock::reset()
{
  // Pick random block.
  this->d_currentBlockIndex = rand() % this->d_blocks.size();

  // Set position to middle of the top, with downwards movement.
  unsigned short halfBlock = this->currentBlock().width() / 2;
  unsigned short halfGrid  = this->d_tetrisGrid->width() / 2;
  this->d_position = Point2D(halfGrid - halfBlock, 0);
  this->d_move = Point2D(0, 1);
}