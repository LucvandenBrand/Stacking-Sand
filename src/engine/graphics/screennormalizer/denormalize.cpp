#include "screennormalizer.ih"

SDL_Rect ScreenNormalizer::deNormalize(float x, float y, float width, float height)
{
  return {x * d_width, y * d_height, width * d_width, height * d_height};
}