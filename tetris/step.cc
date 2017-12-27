#include "tetris.ih"

void Tetris::step()
{
  this->d_tetrisMachine->step();
  this->d_tetrisBlock->step();
}
