#include "window.ih"

SDL_Renderer &Window::sdlRenderer()
{
  return *(this->d_renderer);
}
