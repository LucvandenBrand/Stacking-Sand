#include "pausemenuinputparser.ih"

void PauseMenuInputParser::parse(InputState inputState)
{
  if (inputState.upButtons & START)
    this->d_pauseMenuModel->toggle();
  if (inputState.downButtons & ESCAPE)
    this->d_pauseMenuModel->kill();
}
