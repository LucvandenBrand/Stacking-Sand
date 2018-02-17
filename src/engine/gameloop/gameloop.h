#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "gameloop.ih"

class GameLoop
{
public:
  /* Iterate over all games and update them whilst they are alive. */
  static void loop(vector<Game> &games, SDL_Renderer &sdlRenderer);
private:
  static constexpr float MAX_DELTA_TIME = 0.17f;
  static const int MILLI_IN_SECONDS = 1000;
};

#endif /* GAMELOOP_H */
