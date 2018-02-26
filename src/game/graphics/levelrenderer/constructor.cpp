#include "levelrenderer.ih"

LevelRenderer::LevelRenderer(TextureFactory &textureFactory, LevelModel *levelModel)
  : d_levelModel(levelModel)
{
  initTextures(textureFactory);
}