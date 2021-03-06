#include "pausemenumodel.ih"

PauseMenuModel::PauseMenuModel(initializer_list<Pauseble*> pausebles,  GameOverModel &gameOverModel)
  : Model(), d_pausebles(pausebles), d_gameOverModel(gameOverModel)
{
  for (auto &pauseble : d_pausebles)
    pauseble->paused(d_paused);
}