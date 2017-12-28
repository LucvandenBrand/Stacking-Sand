#include "tetrisblock.ih"

Grid TetrisBlock::currentBlock()
{
  return this->d_blocks[this->d_currentBlockIndex];
}
