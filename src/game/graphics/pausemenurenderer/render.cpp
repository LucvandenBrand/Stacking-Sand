#include "pausemenurenderer.ih"

void PauseMenuRenderer::render(SDL_Renderer &sdlRenderer)
{
  if (this->d_pauseMenuModel->paused())
  {
    /* Create a dark rectangle over the screen. */
    int renderWidth = 0, renderHeight = 0;
    SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);
    SDL_SetRenderDrawColor(&sdlRenderer, 0, 0, 0, 150);
    SDL_Rect rectangle = {0, 0, renderWidth, renderHeight};
    SDL_RenderFillRect(&sdlRenderer, &rectangle);

    /* Draw a pause symbol: two rectangles at the centre of the screen.*/
    auto pauseBlockWidth  = (int) (renderWidth * 0.03);
    auto pauseBlockHeight = pauseBlockWidth * 2;
    auto pauseBlocksX     = (int) (renderWidth / 2 - pauseBlockWidth * 2.5 / 2);
    auto pauseBlocksY     = renderHeight / 2 - pauseBlockHeight / 2;
    rectangle = {pauseBlocksX, pauseBlocksY, pauseBlockWidth, pauseBlockHeight};
    SDL_SetRenderDrawColor(&sdlRenderer, 255, 255, 255, 150);
    SDL_RenderFillRect(&sdlRenderer, &rectangle);

    pauseBlocksX += (int) (1.5 * pauseBlockWidth);
    rectangle = {pauseBlocksX, pauseBlocksY, pauseBlockWidth, pauseBlockHeight};
    SDL_RenderFillRect(&sdlRenderer, &rectangle);
  }
}

