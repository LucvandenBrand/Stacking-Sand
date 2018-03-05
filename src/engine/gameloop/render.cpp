#include "gameloop.ih"

void GameLoop::render(vector<GameRenderer*> gameRenderers, SDL_Renderer &sdlRenderer)
{
  // Render all game renderers.
  SDL_RenderClear(&sdlRenderer);
  for (GameRenderer *gameRenderer : gameRenderers)
  {
    gameRenderer->render(sdlRenderer);
  }
  SDL_RenderPresent(&sdlRenderer);
}
