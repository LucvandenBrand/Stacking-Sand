#include "gameovermodel.ih"

void GameOverModel::step(double deltaTime)
{
  if (gameOver())
  {
    d_gameOverTransition += deltaTime * SCALE_TRANSITION;
    d_gameOverTransition = fmin(1.0f, d_gameOverTransition);
  }
}