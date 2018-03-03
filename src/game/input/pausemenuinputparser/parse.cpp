#include "pausemenuinputparser.ih"

void PauseMenuInputParser::parse(InputState inputState)
{
  if ((inputState.upButtons & START) && !d_pauseMenuModel->gameOver())
    d_pauseMenuModel->toggle();
  if (inputState.downButtons & ESCAPE)
    d_pauseMenuModel->kill();
}
