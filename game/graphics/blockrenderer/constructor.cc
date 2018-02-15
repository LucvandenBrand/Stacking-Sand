#include "blockrenderer.ih"

BlockRenderer::BlockRenderer(SDL_Renderer &sdlRenderer, BlockModel *blockModel)
  : GridRenderer(sdlRenderer), d_blockModel(blockModel)
{ }
