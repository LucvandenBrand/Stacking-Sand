#include "killinputparser.ih"

void KillInputParser::parse(InputState inputState)
{
  if (inputState.downButtons & ESCAPE)
    d_model->kill();
}
