#include "pausemenuinputparser.ih"

void PauseMenuInputParser::parse(ButtonState buttonState)
{
  if (buttonState & START)
    this->d_pauseMenuModel->toggle();
  if (buttonState & ESCAPE)
    this->d_pauseMenuModel->kill();
}
