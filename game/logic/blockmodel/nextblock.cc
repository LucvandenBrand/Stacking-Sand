#include "blockmodel.ih"

Grid BlockModel::nextBlock()
{
  return this->d_blocks[this->d_nextBlockIndex];
}
