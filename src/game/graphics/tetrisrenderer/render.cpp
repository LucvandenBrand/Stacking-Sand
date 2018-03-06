#include "tetrisrenderer.ih"

void TetrisRenderer::render(SDL_Renderer &sdlRenderer, double deltaTime)
{
  // Determine the tetris grid size and offset.
  Grid grid = d_tetrisModel->grid();
  int renderWidth = 0, renderHeight = 0;
  SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);
  int cellSize = renderHeight / grid.height();
  int renderGridWidth = cellSize* grid.width();

  // Draw background and shadow rectangle.
  renderBackground(sdlRenderer, cellSize*SCALE_BACKGROUND_TILE);

  SDL_Color bgColor = {0, 0, 0, 50};
  SDL_SetRenderDrawColor(&sdlRenderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
  SDL_Rect rectangle = {renderWidth/2 - renderGridWidth/2, 0, renderGridWidth, renderHeight};
  d_shadowBrush.drawRectangle(sdlRenderer, rectangle);

  // Draw the tetris grid.
  renderGrid(sdlRenderer, grid, rectangle);

  // Draw the current score.
  renderScore(sdlRenderer);

  // Draw legend.
  renderLegend(sdlRenderer);
}
