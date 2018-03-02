#include "pausemenumodel.ih"

void PauseMenuModel::toggle()
{
  this->d_paused = !this->d_paused;
  this->d_firstStart = false;

  for (auto &pauseble : this->d_pausebles)
    pauseble->paused(this->d_paused);
}