#include "screennormalizer.ih"

float ScreenNormalizer::normalizeWidth(int pixelCoord)
{
  return 1.0f * pixelCoord / d_width;
}