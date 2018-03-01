#include "gameoverinputparser.ih"

void GameOverInputParser::parse(InputState inputState)
{
  if ((inputState.upButtons & START) && d_gameOverModel->gameOver())
    d_gameOverModel->reset();
  if (inputState.downButtons & ESCAPE)
    d_gameOverModel->kill();
}
