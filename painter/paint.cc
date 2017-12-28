#include "painter.ih"

void Painter::paint()
{
  Grid currentgrid  = this->d_tetris->grid();
  Grid currentBlock = this->d_tetris->tetrisBlock().currentBlock();
  int score         = this->d_tetris->tetrisMachine().score();

  // Clear the screen.
  SDL_FillRect(this->d_screenSurface, NULL,
               SDL_MapRGB(this->d_screenSurface->format,
                          0xFF, 0xFF, 0xFF));

  // Update the surface (flip buffers).
  SDL_UpdateWindowSurface(this->d_window);
}
