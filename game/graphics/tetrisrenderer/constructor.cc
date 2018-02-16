#include "tetrisrenderer.ih"

TetrisRenderer::TetrisRenderer(TextureFactory &textureFactory, TetrisModel *tetrisModel)
  : GridRenderer(textureFactory), d_tetrisModel(tetrisModel)
{ }
