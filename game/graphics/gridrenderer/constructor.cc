#include "gridrenderer.ih"

GridRenderer::GridRenderer(SDL_Renderer *sdlRenderer)
{
  this->initTextures(sdlRenderer);
}
