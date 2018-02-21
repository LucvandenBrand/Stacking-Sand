#include "blockrenderer.ih"

void BlockRenderer::render(SDL_Renderer &sdlRenderer)
{
  Grid grid = *(this->d_blockModel->grid());

  // Determine the tetris grid size and offset.
  int renderWidth = 0, renderHeight = 0;
  SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);
  int cellSize = renderHeight / grid.height();
  int renderGridWidth = cellSize * grid.width();
  Point2D offset = Point2D(renderWidth/2 - renderGridWidth/2, 0);

  Grid blockGrid = this->d_blockModel->currentBlock();
  offset += this->d_blockModel->position() * cellSize;
  SDL_Rect rectangle = {offset.x, offset.y,
                        blockGrid.width() * cellSize,
                        blockGrid.height() * cellSize};
  this->renderGrid(sdlRenderer, blockGrid, rectangle);
  this->renderNextBlock(sdlRenderer, cellSize);
}
