#include "blockrenderer.ih"

BlockRenderer::BlockRenderer(TextureFactory &textureFactory, BlockModel *blockModel)
  : GridRenderer(textureFactory), d_blockModel(blockModel)
{ }
