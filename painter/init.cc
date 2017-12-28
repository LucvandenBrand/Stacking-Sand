#include "painter.ih"

bool Painter::init()
{
  // Initialize the SDL library
  if (SDL_Init(SDL_INIT_VIDEO) >= 0)
  {
    // Create a window.
    this->d_window = SDL_CreateWindow(this->c_TITLE,
                                      SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED,
                                      this->c_SCREEN_WIDTH,
                                      this->c_SCREEN_HEIGHT,
                                      SDL_WINDOW_SHOWN);

    // If succesful, retrieve the surface of the window.
    if (this->d_window)
      this->d_screenSurface = SDL_GetWindowSurface(this->d_window);
    else
      return false;
  }
  else
    return false;

  // Everything went fine, return success.
  return true;
}
