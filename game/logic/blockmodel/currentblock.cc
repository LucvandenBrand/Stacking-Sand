#include "blockmodel.ih"

Grid BlockModel::currentBlock()
{
  return this->d_blocks[this->d_currentBlockIndex];
}
