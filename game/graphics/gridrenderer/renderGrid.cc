#include "gridrenderer.ih"

void GridRenderer::renderGrid(SDL_Renderer& sdlRenderer, Grid grid, Point2D size,
                              Point2D offset)
{
  // Calculate the dimensions we will work with.
  int gridWidth  =  grid.width();
  int gridHeight =  grid.height();
  int cellWidth  = size.x  / gridWidth;
  int cellHeight = size.y / gridHeight;

  // Draw each cell.
  for (unsigned short posY = 0; posY < gridHeight; ++posY)
  {
    for (unsigned short posX = 0; posX < gridWidth; ++posX)
    {
      unsigned short cell = *(grid.cell(Point2D(posX, posY)));
      unsigned short screenX  = posX * cellWidth + offset.x;
      unsigned short screenY  = posY * cellHeight + offset.y;

      // Draw a cell, the texture depends on the cell value.
      if (cell > 0)
      {
        SDL_Rect rectangle = {screenX, screenY, cellWidth, cellHeight};
        this->d_cellTextures[cell-1].render(&sdlRenderer, rectangle);
      }
    }
  }
}
