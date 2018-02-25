#ifndef SCREEN_NORMALIZER
#define SCREEN_NORMALIZER

#include "screennormalizer.ih"

class ScreenNormalizer
{
public:
  explicit ScreenNormalizer(SDL_Renderer &sdlRenderer);

  /* Convert normalized floats to true pixel sizes. */
  SDL_Rect deNormalize(float x, float y, float width, float height);

  /* Convert pixel coordinate to normalized float. */
  float normalizeWidth(int pixelCoord);
  float normalizeHeight(int pixelCoord);
  float ratio();

private:
  int d_width, d_height;
};

#endif /* SCREEN_NORMALIZER */