#include "tetrismodel.ih"

double TetrisModel::waitTime()
{
  return DELAY_LEVEL[level()];
}
