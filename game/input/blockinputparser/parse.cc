#include "blockinputparser.ih"

void BlockInputParser::parse(ButtonState buttonState)
{
  if (buttonState & LEFT)
    this->d_blockModel->move(Point2D(-1, 0));
  if (buttonState & RIGHT)
    this->d_blockModel->move(Point2D(1, 0));
  if (buttonState & ESCAPE)
    this->d_blockModel->kill();
}
