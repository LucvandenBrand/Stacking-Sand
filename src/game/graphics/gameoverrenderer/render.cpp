#include "gameoverrenderer.ih"

void GameOverRenderer::render(SDL_Renderer &sdlRenderer)
{
  if (d_gameOverModel->gameOver())
  {
    /* Create a dark rectangle over the screen. */
    int renderWidth = 0, renderHeight = 0;
    SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);
    SDL_SetRenderDrawColor(&sdlRenderer, 0, 0, 0, 150);
    SDL_Rect rectangle = {0, 0, renderWidth, renderHeight};
    SDL_RenderFillRect(&sdlRenderer, &rectangle);
  }
}