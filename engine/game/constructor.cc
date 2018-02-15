#include "game.ih"

Game::Game(GameRenderer *renderer, InputParser *inputParser, Model *model)
  : d_renderer(renderer),
    d_inputParser(inputParser),
    d_model(model)
{}
