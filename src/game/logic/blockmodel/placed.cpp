#include "blockmodel.ih"

bool BlockModel::placed()
{
  return d_shouldReset;
}