#include "tetrisinputparser.ih"

void TetrisInputParser::parse(ButtonState buttonState)
{
  if (buttonState & DOWN)
    this->d_tetrisModel->speedup(SPEEDUP_TIME);
  if (buttonState & ESCAPE)
    this->d_tetrisModel->kill();
}
