#ifndef SCREEN_NORMALIZER
#define SCREEN_NORMALIZER

#include "screennormalizer.ih"

/**
 * Normalizes screen coordinates to [0,1] and back.
 * Useful for making the game resolution independent.
 */
class ScreenNormalizer
{
public:
  /**
   * Constructs normalizer based on the SDL renderer's size.
   */
  explicit ScreenNormalizer(SDL_Renderer &sdlRenderer);

  /**
   * Convert normalized floats to true pixel sizes.
   */
  SDL_Rect deNormalize(float x, float y, float width, float height);

  /**
   * Convert width pixel coordinate to normalized float.
   */
  float normalizeWidth(int pixelCoord);

  /**
   * Convert height pixel coordinate to normalized float.
   */
  float normalizeHeight(int pixelCoord);

  /**
   * Return the height / width ratio.
   */
  float ratio();

private:
  int d_width, d_height;
};

#endif // SCREEN_NORMALIZER