#include "gameloop.ih"

void GameLoop::render(vector<GameRenderer*> gameRenderers, SDL_Renderer &sdlRenderer)
{
  // Render all game renderers.
  auto waitTime = chrono::milliseconds(UPDATE_SPEED_MAIN);
  double deltaTime = 1.0 * waitTime.count() / MILLI_IN_SECONDS;
  SDL_RenderClear(&sdlRenderer);
  for (GameRenderer *gameRenderer : gameRenderers)
  {
    gameRenderer->render(sdlRenderer, deltaTime);
  }
  SDL_RenderPresent(&sdlRenderer);
}
