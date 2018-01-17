#include "tetrisblock.ih"

Grid TetrisBlock::nextBlock()
{
  return this->d_blocks[this->d_nextBlockIndex];
}
