#include "gridrenderer.ih"

void GridRenderer::renderGrid(SDL_Renderer &sdlRenderer, Grid grid, SDL_Rect rectangle)
{
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
        this->d_cellTextures[cell-1].render(sdlRenderer, cellRectangle);
      }
    }
  }
}
