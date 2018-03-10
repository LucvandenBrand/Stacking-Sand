#include "tetrisinputparser.ih"

void TetrisInputParser::parse(InputState inputState)
{
  if (inputState.downButtons & ESCAPE)
    d_tetrisModel->kill();
}
