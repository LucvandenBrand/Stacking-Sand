#include "tetrismodel.ih"

void TetrisModel::speedup(float speedupTime)
{
  d_timeToWait -= speedupTime;
}
