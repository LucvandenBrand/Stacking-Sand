#include "pausemenurenderer.ih"

void PauseMenuRenderer::renderStart(SDL_Renderer &sdlRenderer, double deltaTime)
{
  // Update animation.
  d_titleAnimation.update(deltaTime);
  d_startButtonAnimation.update(deltaTime);

  ScreenNormalizer normalizer(sdlRenderer);

  /* Create a dark rectangle over the screen. */
  SDL_SetRenderDrawColor(&sdlRenderer, 150, 170, 200, 220);
  SDL_Rect rectangle = normalizer.deNormalize(0, 0, 1, 1);
  SDL_RenderFillRect(&sdlRenderer, &rectangle);

  /* Draw the game's title. */
  float titleWidth  = 0.8f;
  float titleHeight = titleWidth / normalizer.normalizeWidth(d_gameTitle->width())
                      * normalizer.normalizeHeight(d_gameTitle->height());
  float titleX = 0.5f - titleWidth / 2;
  float titleY = 0.45f - titleHeight / 2 + (float) (d_titleAnimation.get() + d_startButtonAnimation.get());
  SDL_Rect titleRectangle = normalizer.deNormalize(titleX, titleY, titleWidth, titleHeight);
  d_gameTitle->render(sdlRenderer, titleRectangle);

  /* Draw the start controls. */
  float controlWidth = 0.2f;
  float controlHeight = controlWidth / normalizer.normalizeWidth(d_startControls->width())
                        * normalizer.normalizeHeight(d_startControls->height());
  float controlX = 0.5f - controlWidth / 2;
  float controlY = 0.9f - controlHeight / 2 - (float) (d_titleAnimation.get() + d_startButtonAnimation.get());
  SDL_Rect controlRectangle = normalizer.deNormalize(controlX, controlY, controlWidth, controlHeight);
  d_startControls->render(sdlRenderer, controlRectangle);

  // Draw credits.
  TextureFactory textureFactory(&sdlRenderer);
  unique_ptr<Texture> credit = textureFactory.fontTexture("Brand - 2018", *d_creditFont, {55, 69, 71, 255});
  float creditWidth  = 0.15f;
  float creditHeight = creditWidth / normalizer.normalizeWidth(credit->width())
                * normalizer.normalizeHeight(credit->height());
  float creditX      = 1 - creditWidth;
  float creditY      = 1 - creditHeight;
  SDL_Rect creditRectangle = normalizer.deNormalize(creditX, creditY, creditWidth, creditHeight);
  credit->render(sdlRenderer, creditRectangle);
}