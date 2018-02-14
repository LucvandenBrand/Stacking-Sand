#include "tetrismodel.ih"

TetrisModel::TetrisModel()
{
  this->d_grid = new Grid(TETRIS_WIDTH, TETRIS_HEIGHT);
  this->d_score = 0;
  this->d_timeToWait = DELAY_LEVEL0;
}
