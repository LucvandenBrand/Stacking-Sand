#include "window.ih"

SDL_Renderer &Window::sdlRenderer()
{
  return *d_renderer;
}
