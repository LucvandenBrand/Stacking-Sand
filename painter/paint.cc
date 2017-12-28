#include "painter.ih"

void Painter::paint()
{
  Grid currentgrid  = this->d_tetris->grid();
  Grid currentBlock = this->d_tetris->tetrisBlock().currentBlock();
  int score         = this->d_tetris->tetrisMachine().score();

  // Clear the screen to a grey background.
  SDL_FillRect(this->d_screenSurface, NULL,
               SDL_MapRGB(this->d_screenSurface->format,
                          0xAF, 0xAF, 0xAF));

  // Draw the tetris grid.
  unsigned short cellSize = this->c_SCREEN_HEIGHT / currentgrid.height();
  for (unsigned short posY = 0; posY < currentgrid.height(); ++posY)
  {
    for (unsigned short posX = 0; posX < currentgrid.width(); ++posX)
    {
      unsigned short cell = *(currentgrid.cell(Point2D(posX, posY)));
      unsigned short screenX  = posX * cellSize;
      unsigned short screenY  = posY * cellSize;

      // Draw a cell, the color depends on the cell value.
      uint8_t color = 63 * cell;
      SDL_Rect rectangle = {screenX, screenY, cellSize, cellSize};
      SDL_FillRect(this->d_screenSurface, &rectangle,
                   SDL_MapRGB(this->d_screenSurface->format,
                              color, color, color));
    }
  }

  // Update the surface (flip buffers).
  SDL_UpdateWindowSurface(this->d_window);
}
