#include "blockmodel.ih"

bool BlockModel::overlap(Point2D newPosition)
{
  return overlap(newPosition, currentBlock());
}
