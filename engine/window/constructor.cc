#include "window.ih"

Window::Window()
{
  if (!init())
    throw runtime_error(SDL_GetError()); 
}
