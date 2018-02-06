#include "tetris.ih"

Tetris::Tetris()
{
  this->d_grid = new Grid(TETRIS_WIDTH, TETRIS_HEIGHT);
  this->d_tetrisMachine = new TetrisMachine(this->d_grid);
  this->d_tetrisBlock = new TetrisBlock(this->d_grid);
  this->d_goalTicks = clock();
}
