#include "tetrisrenderer.ih"

TetrisRenderer::~TetrisRenderer()
{
  free(d_gameFont);
  delete d_background;
}