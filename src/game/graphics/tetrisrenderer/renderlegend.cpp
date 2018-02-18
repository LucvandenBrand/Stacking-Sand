#include "tetrisrenderer.ih"

void TetrisRenderer::renderLegend(SDL_Renderer &sdlRenderer, int cellSize)
{
  int renderWidth = 0, renderHeight = 0;
  SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);

  // Draw the shadow box.
  int legendX = (int) (renderWidth * 0.02);
  int legendY = (int) (renderHeight * 0.5);
  int legendW = (int) (renderWidth * 0.32);
  int legendH = (int) (renderHeight * 0.48);
  SDL_Rect rectangle = {legendX, legendY, legendW, legendH};
  this->d_shadowBrush.drawRectangle(sdlRenderer, rectangle);

  // Draw the cells.
  int cellX = (int) (legendX + legendW * 0.1);
  int cellY = (int) (legendY + legendH * 0.2);
  SDL_Rect cellRectangle = {cellX, cellY, cellSize, cellSize};
  this->d_cellTextures[0].render(sdlRenderer, cellRectangle);
  cellRectangle.y += renderHeight * 0.1;
  this->d_cellTextures[1].render(sdlRenderer, cellRectangle);
}
