#include "painter.ih"

void Painter::paintGrid(Grid currentGrid, unsigned short cellSize,
                        Point2D offset)
{
  for (unsigned short posY = 0; posY < currentGrid.height(); ++posY)
  {
    for (unsigned short posX = 0; posX < currentGrid.width(); ++posX)
    {
      unsigned short cell = *(currentGrid.cell(Point2D(posX, posY)));
      unsigned short screenX  = (posX + offset.x) * cellSize;
      unsigned short screenY  = (posY + offset.y) * cellSize;

      // Draw a cell, the color depends on the cell value.
      Texture *cellTexture;
      if (cell == 0)
        cellTexture = this->d_dirtTexture;
      else
        cellTexture = this->d_sandTexture;

      //uint8_t color = 63 * cell;
      SDL_Rect rectangle = {screenX, screenY, cellSize, cellSize};
      cellTexture->render(this->d_renderer, rectangle);
    }
  }
}
