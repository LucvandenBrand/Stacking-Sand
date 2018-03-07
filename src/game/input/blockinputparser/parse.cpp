#include "blockinputparser.ih"

void BlockInputParser::parse(InputState inputState)
{
  if (inputState.upButtons & UP)
    d_blockModel->rotate();

  if (inputState.downButtons & LEFT)
    d_blockModel->move(Point2D(-1, 0));
  if (inputState.downButtons & RIGHT)
    d_blockModel->move(Point2D(1, 0));
  if (inputState.downButtons & ESCAPE)
    d_blockModel->kill();
}
