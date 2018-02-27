#include "levelrenderer.ih"

void LevelRenderer::render(SDL_Renderer &sdlRenderer)
{
  float level = d_levelModel->level();

  float difference, index;
  difference = modf(level , &index);

  // Always draw bottom level.
  if (index >= d_newspapers.size())
    index = d_newspapers.size()-1;

  ScreenNormalizer normalizer(sdlRenderer);

  float width  = 0.3;
  float height = 0.7;
  float posX   = 0.67;
  float posY   = 0.25;
  SDL_Rect rectangle = normalizer.deNormalize(posX, posY, width, height);
  d_newspapers[index].render(sdlRenderer, rectangle);

  // Draw top level, if it exists.
  index++;
  if (index < d_newspapers.size())
  {
    float shiftPosY = posY + 1-1*difference;
    rectangle = normalizer.deNormalize(posX, shiftPosY, width, height);
    d_newspapers[index].render(sdlRenderer, rectangle);
  }
}
