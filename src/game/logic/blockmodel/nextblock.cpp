#include "blockmodel.ih"

Grid BlockModel::nextBlock()
{
  return d_blocks[d_nextBlockIndex];
}
