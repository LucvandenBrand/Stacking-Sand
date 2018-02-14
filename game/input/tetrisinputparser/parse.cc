#include "tetrisinputparser.ih"

void TetrisInputParser::parse(ButtonState buttonState)
{
  if (buttonState & ESCAPE)
    this->d_tetrisModel->kill();
}
