#ifndef GAME_H
#define GAME_H

#include "game.ih"

/* An entity in the game that needs to be drawn and reacts to input. */
class Game
{
public:
  Game(GameRenderer &renderer, InputParser &inputParser, Model &model);

  /* Update the state of the game. */
  void update(SDL_Renderer &sdlRenderer, InputState inputState, float deltaTime);

  /* Return if the model is alive, if not, the game should be destroyed. */
  bool alive();

private:
  GameRenderer *d_renderer;
  InputParser *d_inputParser;
  Model *d_model;
};

#endif /* GAME_H */
