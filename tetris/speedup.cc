#include "tetris.ih"

void Tetris::speedup(int speedupTime)
{
  this->d_goalTicks -= speedupTime;
}
