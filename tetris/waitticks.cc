#include "tetris.ih"

int Tetris::waitTicks()
{
  const int START_WAIT = 150000;
  int wait = START_WAIT - this->tetrisMachine().score()*1000;
  return wait < 0 ? 0 : wait;
}
