#include "tetris.ih"

void Tetris::step()
{
  int curTicks = clock();
  if (this->d_goalTicks <= curTicks)
  {
    this->d_goalTicks = curTicks + this->d_waitTicks;
    this->d_tetrisMachine->step();
    this->d_tetrisBlock->step();
  }
}
