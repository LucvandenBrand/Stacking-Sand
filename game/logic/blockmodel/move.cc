#include "blockmodel.ih"

void BlockModel::move(Point2D shift)
{
  cout << "MOVE! \n";
  this->d_move = shift;
}
