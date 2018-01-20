#include "painter.ih"

void Painter::paintGrid(Grid currentGrid, unsigned short cellSize,
                        Point2D offset)
{
  for (unsigned short posY = 0; posY < currentGrid.height(); ++posY)
  {
    for (unsigned short posX = 0; posX < currentGrid.width(); ++posX)
    {
      unsigned short cell = *(currentGrid.cell(Point2D(posX, posY)));
      unsigned short screenX  = posX * cellSize + offset.x;
      unsigned short screenY  = posY * cellSize + offset.y;

      // Draw a cell, the texture depends on the cell value.
      if (cell > 0)
      {
        SDL_Rect rectangle = {screenX, screenY, cellSize, cellSize};
        this->d_blockTextures[cell-1].render(this->d_renderer, rectangle);
      }
    }
  }
}
