#include "gameovermodel.ih"

void GameOverModel::reset()
{
  cout << "RESET" << endl;
  d_tetrisModel->reset();
  d_blockModel->reset();
}