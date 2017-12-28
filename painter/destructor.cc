#include "painter.ih"

Painter::~Painter()
{
  // Freeing the window also frees the surface.
  SDL_DestroyWindow(this->d_window);
  this->d_window = NULL;
  this->d_screenSurface = NULL;

  SDL_Quit();
}
