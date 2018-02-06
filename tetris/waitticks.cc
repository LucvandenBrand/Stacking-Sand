#include "tetris.ih"

int Tetris::waitTicks()
{
  int speed;
  if (this->tetrisMachine().score() >= SCORE_LEVEL6)
    speed = SPEED_LEVEL6;
  else if (this->tetrisMachine().score() >= SCORE_LEVEL5)
    speed = SPEED_LEVEL5;
  else if (this->tetrisMachine().score() >= SCORE_LEVEL4)
    speed = SPEED_LEVEL4;
  else if (this->tetrisMachine().score() >= SCORE_LEVEL3)
    speed = SPEED_LEVEL3;
  else if (this->tetrisMachine().score() >= SCORE_LEVEL2)
    speed = SPEED_LEVEL2;
  else if (this->tetrisMachine().score() >= SCORE_LEVEL1)
    speed = SPEED_LEVEL1;
  else
    speed = SPEED_LEVEL0;

  return speed;
}
