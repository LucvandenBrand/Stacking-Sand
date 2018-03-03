#include "window.ih"

Window::~Window()
{
  // Freeing the window also frees the surface.
  SDL_DestroyRenderer(d_renderer);
  SDL_DestroyWindow(d_window);

  // Shut down subsystems.
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
