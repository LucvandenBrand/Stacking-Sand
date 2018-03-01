#include "blockmodel.ih"

Grid BlockModel::currentBlock()
{
  return d_blocks[d_currentBlockIndex];
}
