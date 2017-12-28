#include "controller.ih"

bool Controller::processEvents()
{
  SDL_Event e;
  while(SDL_PollEvent(&e) != 0)
  {
    switch (e.type) {
      case SDL_QUIT: // Exit button is pressed.
        return false;
    }
  }
  return true;
}
