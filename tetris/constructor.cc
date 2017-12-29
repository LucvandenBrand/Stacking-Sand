#include "tetris.ih"

Tetris::Tetris()
{
  this->d_grid = new Grid(10, 20);
  this->d_tetrisMachine = new TetrisMachine(this->d_grid);
  this->d_tetrisBlock = new TetrisBlock(this->d_grid);
  this->d_waitTicks = 100000;
  this->d_goalTicks = clock();
}
