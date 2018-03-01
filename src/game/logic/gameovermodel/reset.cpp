#include "gameovermodel.ih"

void GameOverModel::reset()
{
  d_gameOverTransition = 0;
  d_tetrisModel->reset();
  d_blockModel->reset();
}