#include "blockmodel.ih"

void BlockModel::reset()
{
  // Set a new current block and pick a new random next block.
  d_currentBlockIndex = d_nextBlockIndex;
  d_nextBlockIndex = (int) (rand() % d_blocks.size());

  // Set position to middle of the top, with downwards movement.
  auto halfBlock = (unsigned short) (currentBlock().width() / 2);
  auto halfGrid  = (unsigned short) (grid().width() / 2);
  d_position = Point2D(halfGrid - halfBlock, 0);
  d_move = Point2D(0, 0);

  // If overlapping at init, it is game-over.
  d_gameOver = overlap(d_position);
}
