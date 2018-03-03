#include "gridrenderer.ih"

GridRenderer::~GridRenderer()
{
  // Free allocated textures.
  d_cellTextures.clear();
}
