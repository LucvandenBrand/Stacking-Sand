#include "pausemenurenderer.ih"

void PauseMenuRenderer::renderPause(SDL_Renderer &sdlRenderer, double deltaTime)
{
  // Update animations.
  d_pauseButtonAnimation.update(deltaTime);

  ScreenNormalizer normalizer(sdlRenderer);

  /* Create a dark rectangle over the screen. */
  SDL_SetRenderDrawColor(&sdlRenderer, 0, 0, 0, 150);
  SDL_Rect rectangle = normalizer.deNormalize(0, 0, 1, 1);
  SDL_RenderFillRect(&sdlRenderer, &rectangle);

  /* Draw a pause symbol: two rectangles at the centre of the screen.*/
  float pauseBlockWidth  = 0.03;
  float pauseBlockHeight = pauseBlockWidth * 4 - (float) d_pauseButtonAnimation.get();
  float pauseBlocksX     = 0.5f - pauseBlockWidth * 2.5f / 2;
  float pauseBlocksY     = 0.5f - pauseBlockHeight / 2;
  rectangle = normalizer.deNormalize(pauseBlocksX, pauseBlocksY, pauseBlockWidth, pauseBlockHeight);
  SDL_SetRenderDrawColor(&sdlRenderer, 255, 255, 255, 150);
  SDL_RenderFillRect(&sdlRenderer, &rectangle);

  pauseBlocksX += 1.5 * pauseBlockWidth;
  rectangle = normalizer.deNormalize(pauseBlocksX, pauseBlocksY, pauseBlockWidth, pauseBlockHeight);
  SDL_RenderFillRect(&sdlRenderer, &rectangle);
}