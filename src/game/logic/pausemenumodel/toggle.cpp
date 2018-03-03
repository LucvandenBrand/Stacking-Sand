#include "pausemenumodel.ih"

void PauseMenuModel::toggle()
{
  d_paused = !d_paused;
  d_firstStart = false;

  for (auto &pauseble : d_pausebles)
    pauseble->paused(d_paused);
}