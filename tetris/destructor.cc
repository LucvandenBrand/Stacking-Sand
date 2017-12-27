#include "tetris.ih"

Tetris::~Tetris()
{
  delete this->d_tetrisMachine;
  delete this->d_tetrisBlock;
  delete this->d_grid;
}
