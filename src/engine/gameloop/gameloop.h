#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "gameloop.ih"

class GameLoop
{
public:
  void loop(vector<Model*> models, vector<InputParser*> inputParsers,
            vector<GameRenderer*> gameRenderers);

private:
  /* Iterate over all games and update them whilst they are alive. */
  void loopModels(vector<Model*> models);

  /* Pass the current input to all input parsers. */
  void parseInput(vector<InputParser*> inputParsers);

  /* Render all game renderers to the screen. */
  void render(vector<GameRenderer*> gameRenderers, SDL_Renderer &sdlRenderer);

  /* Should the main loop close.*/
  bool d_running = false;

  /* Model update speed in milliseconds. */
  static constexpr int UPDATE_SPEED_MODELS = 34;

  /* Render and input update speed in milliseconds. */
  static constexpr int UPDATE_SPEED_MAIN = 17;

  static constexpr int MILLI_IN_SECONDS = 1000;
};

#endif /* GAME_LOOP_H */
