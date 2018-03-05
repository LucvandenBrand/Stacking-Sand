#include "tetrismodel.ih"

void TetrisModel::speedup(double speedupTime)
{
  d_timeToWait -= speedupTime;
}
