#include "screennormalizer.ih"

ScreenNormalizer::ScreenNormalizer(SDL_Renderer &sdlRenderer)
{
  SDL_GetRendererOutputSize(&sdlRenderer, &d_width, &d_height);
}