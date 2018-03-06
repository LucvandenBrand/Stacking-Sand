#include "tetrisrenderer.ih"

TetrisRenderer::~TetrisRenderer()
{
  TTF_CloseFont(d_gameFont);
}