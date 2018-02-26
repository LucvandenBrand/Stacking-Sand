#include "killinputparser.ih"

void KillInputParser::parse(InputState inputState)
{
  if (inputState.downButtons & ESCAPE)
    this->d_model->kill();
}
