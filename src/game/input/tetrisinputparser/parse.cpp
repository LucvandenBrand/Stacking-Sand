#include "tetrisinputparser.ih"

void TetrisInputParser::parse(InputState inputState)
{
  if (inputState.downButtons & DOWN)
    d_tetrisModel->speedup(SPEEDUP_TIME);
  if (inputState.downButtons & ESCAPE)
    d_tetrisModel->kill();
}
