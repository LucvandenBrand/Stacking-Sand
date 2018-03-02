#include "pausemenurenderer.ih"

void PauseMenuRenderer::render(SDL_Renderer &sdlRenderer)
{
  ScreenNormalizer normalizer(sdlRenderer);
  if (d_pauseMenuModel->firstStart())
  {
    /* Create a dark rectangle over the screen. */
    SDL_SetRenderDrawColor(&sdlRenderer, 150, 170, 200, 220);
    SDL_Rect rectangle = normalizer.deNormalize(0, 0, 1, 1);
    SDL_RenderFillRect(&sdlRenderer, &rectangle);

    /* Draw the game's title. */
    float titleWidth  = 0.8f;
    float titleHeight = titleWidth / normalizer.normalizeWidth(d_gameTitle->width())
                                   * normalizer.normalizeHeight(d_gameTitle->height());
    float titleX = 0.5f - titleWidth / 2;
    float titleY = 0.45f - titleHeight / 2;
    SDL_Rect titleRectangle = normalizer.deNormalize(titleX, titleY, titleWidth, titleHeight);
    d_gameTitle->render(sdlRenderer, titleRectangle);

    /* Draw the start controls. */
    float controlWidth = 0.2f;
    float controlHeight = controlWidth / normalizer.normalizeWidth(d_startControls->width())
                                       * normalizer.normalizeHeight(d_startControls->height());
    float controlX = 0.5f - controlWidth / 2;
    float controlY = 0.9f - controlHeight / 2;
    SDL_Rect controlRectangle = normalizer.deNormalize(controlX, controlY, controlWidth, controlHeight);
    d_startControls->render(sdlRenderer, controlRectangle);
  }
  else if (d_pauseMenuModel->paused())
  {
    /* Create a dark rectangle over the screen. */
    SDL_SetRenderDrawColor(&sdlRenderer, 0, 0, 0, 150);
    SDL_Rect rectangle = normalizer.deNormalize(0, 0, 1, 1);
    SDL_RenderFillRect(&sdlRenderer, &rectangle);

    /* Draw a pause symbol: two rectangles at the centre of the screen.*/
    float pauseBlockWidth  = 0.03;
    float pauseBlockHeight = pauseBlockWidth * 4;
    float pauseBlocksX     = 0.5f - pauseBlockWidth * 2.5f / 2;
    float pauseBlocksY     = 0.5f - pauseBlockHeight / 2;
    rectangle = normalizer.deNormalize(pauseBlocksX, pauseBlocksY, pauseBlockWidth, pauseBlockHeight);
    SDL_SetRenderDrawColor(&sdlRenderer, 255, 255, 255, 150);
    SDL_RenderFillRect(&sdlRenderer, &rectangle);

    pauseBlocksX += 1.5 * pauseBlockWidth;
    rectangle = normalizer.deNormalize(pauseBlocksX, pauseBlocksY, pauseBlockWidth, pauseBlockHeight);
    SDL_RenderFillRect(&sdlRenderer, &rectangle);
  }
}

