#include "gameloop.ih"

void GameLoop::parseInput(vector<InputParser*> inputParsers)
{
  // Update all living models.
  InputState inputState = Input::getState();
  for (InputParser *inputParser : inputParsers)
  {
    inputParser->parse(inputState);
  }
}
