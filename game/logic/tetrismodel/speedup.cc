#include "tetrismodel.ih"

void TetrisModel::speedup(float speedupTime)
{
  this->d_timeToWait -= speedupTime;
}
