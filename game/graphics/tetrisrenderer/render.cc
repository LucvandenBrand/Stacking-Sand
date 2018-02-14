#include "tetrisrenderer.ih"

void TetrisRenderer::render(SDL_Renderer& sdlRenderer)
{
  Grid grid = *(this->d_tetrisModel->grid());

  // Determine the tetris grid size and offset.
  int renderWidth = 0, renderHeight = 0;
  SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);
  int renderGridWidth = renderHeight / grid.height() * grid.width();
  Point2D size   = Point2D(renderGridWidth, renderHeight);
  Point2D offset = Point2D(renderWidth/2 - renderGridWidth/2, 0);

  this->renderGrid(sdlRenderer, grid, size, offset);
}
