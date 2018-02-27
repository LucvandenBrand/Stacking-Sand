#include "gridrenderer.ih"
#include "../shadowbrush/shadowbrush.ih"

void GridRenderer::renderGrid(SDL_Renderer &sdlRenderer, Grid grid, SDL_Rect rectangle)
{
  ShadowBrush shadowBrush(SHADOW_COLOR, SHADOW_SPREAD);

  // Calculate the dimensions we will work with.
  int gridWidth  =  grid.width();
  int gridHeight =  grid.height();
  int cellWidth  = rectangle.w  / gridWidth;
  int cellHeight = rectangle.h / gridHeight;

  // Draw each cell.
  for (unsigned short posY = 0; posY < gridHeight; ++posY)
  {
    for (unsigned short posX = 0; posX < gridWidth; ++posX)
    {
      unsigned short cell = grid.cell(Point2D(posX, posY));
      int screenX  = posX * cellWidth + rectangle.x;
      int screenY  = posY * cellHeight + rectangle.y;

      // Draw a cell, the texture depends on the cell value.
      if (cell > 0)
      {
        SDL_Rect cellRectangle = {screenX, screenY, cellWidth, cellHeight};
        shadowBrush.drawRectangle(sdlRenderer, cellRectangle);
        d_cellTextures[cell-1].render(sdlRenderer, cellRectangle);
      }
    }
  }
}
