#include "painter.ih"

Painter::~Painter()
{
  // Free allocated classes.
  delete this->d_sandTexture;
  delete this->d_dirtTexture;
  delete this->d_gridTexture;

  // Freeing the window also frees the surface.
  SDL_DestroyRenderer(this->d_renderer);
  SDL_DestroyWindow(this->d_window);

  // Shut down subsystems.
  IMG_Quit();
  SDL_Quit();
}
