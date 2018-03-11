#include "gameloop.ih"

void GameLoop::audio(vector<GameAudio*> gameAudios)
{
  auto waitTime = chrono::milliseconds(UPDATE_SPEED_MAIN);
  double deltaTime = 1.0 * waitTime.count() / MILLI_IN_SECONDS;

  for (GameAudio *gameAudio : gameAudios)
    gameAudio->update(deltaTime);
}