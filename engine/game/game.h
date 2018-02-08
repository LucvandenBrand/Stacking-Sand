#ifndef GAME_H
#define GAME_H

#include "game.ih"

/* An entity in the game that needs to be drawn and reacts to input. */
class Game
{
public:
  Game(GameRenderer* renderer, InputParser* inputParser, Model* model);
  void update(Window& window, ButtonState buttonState, float deltaTime);

private:
  GameRenderer* d_renderer;
  InputParser* d_inputParser;
  Model* d_model;
};

#endif /* GAME_H */
