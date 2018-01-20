#include "painter.ih"

Painter::~Painter()
{
  // Free allocated textures.
  this->d_blockTextures.clear();

  // Close fonts.
  TTF_CloseFont(this->d_gameFont);
  TTF_CloseFont(this->d_largeGameFont);

  // Freeing the window also frees the surface.
  SDL_DestroyRenderer(this->d_renderer);
  SDL_DestroyWindow(this->d_window);

  // Shut down subsystems.
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
