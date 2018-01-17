#include "painter.ih"

Painter::~Painter()
{
  // Free allocated classes.
  delete this->d_sandTexture;
  delete this->d_dirtTexture;
  delete this->d_gridTexture;

  // Close fonts.
  TTF_CloseFont(this->d_gameFont);

  // Freeing the window also frees the surface.
  SDL_DestroyRenderer(this->d_renderer);
  SDL_DestroyWindow(this->d_window);

  // Shut down subsystems.
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
