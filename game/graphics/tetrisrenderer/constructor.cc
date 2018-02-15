#include "tetrisrenderer.ih"

TetrisRenderer::TetrisRenderer(SDL_Renderer &sdlRenderer, TetrisModel *tetrisModel)
  : GridRenderer(sdlRenderer), d_tetrisModel(tetrisModel)
{ }
