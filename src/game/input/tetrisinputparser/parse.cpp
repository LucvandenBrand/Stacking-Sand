#include "tetrisinputparser.ih"

void TetrisInputParser::parse(InputState inputState)
{
  if (inputState.downButtons & DOWN)
    this->d_tetrisModel->speedup(SPEEDUP_TIME);
  if (inputState.downButtons & ESCAPE)
    this->d_tetrisModel->kill();
}
