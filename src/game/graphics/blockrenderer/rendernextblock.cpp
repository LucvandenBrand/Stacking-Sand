#include "blockrenderer.ih"

void BlockRenderer::renderNextBlock(SDL_Renderer &sdlRenderer, int cellSize)
{
  Grid grid = *(this->d_blockModel->grid());

  // Draw the containing shadow rectangle.
  int renderWidth = 0, renderHeight = 0;
  SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);
  auto boxX      = (int) (renderWidth  * 0.25);
  auto boxY      = (int) (renderHeight * 0.01);
  auto boxWidth  = (int) (renderWidth  * 0.1);
  auto boxHeight = (int) (renderHeight * 0.2);
  SDL_Rect boxRectangle = {boxX, boxY, boxWidth, boxHeight};
  this->d_shadowBrush.drawRectangle(sdlRenderer, boxRectangle);

  // Draw the next block.
  Grid blockGrid  = this->d_blockModel->nextBlock();
  int blockWidth  = blockGrid.width() * cellSize;
  int blockHeight = blockGrid.height() * cellSize;
  auto posX       = (int) (boxX + boxWidth / 2.0 - blockWidth / 2.0);
  auto posY       = (int) (boxY + boxHeight / 2.0 - blockHeight / 2.0);
  SDL_Rect rectangle = {posX, posY, blockWidth, blockHeight};
  this->renderGrid(sdlRenderer, blockGrid, rectangle);
}
