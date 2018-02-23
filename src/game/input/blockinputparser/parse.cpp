#include "blockinputparser.ih"

void BlockInputParser::parse(InputState inputState)
{
  if (inputState.downButtons & LEFT)
    this->d_blockModel->move(Point2D(-1, 0));
  if (inputState.downButtons & RIGHT)
    this->d_blockModel->move(Point2D(1, 0));
  if (inputState.downButtons & ESCAPE)
    this->d_blockModel->kill();
}
