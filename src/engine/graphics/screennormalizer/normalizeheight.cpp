#include "screennormalizer.ih"

float ScreenNormalizer::normalizeHeight(int pixelCoord)
{
  return 1.0f * pixelCoord / d_height;
}