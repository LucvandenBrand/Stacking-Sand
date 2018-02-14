#include "gridrenderer.ih"

GridRenderer::~GridRenderer()
{
  // Free allocated textures.
  this->d_cellTextures.clear();
}
