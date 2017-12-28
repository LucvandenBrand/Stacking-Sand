#include "controller.ih"

bool Controller::processEvents()
{
  SDL_Event e;
  while(SDL_PollEvent(&e) != 0)
  {
    // Process window events.
    switch (e.type) {
      case SDL_QUIT: // Exit button is pressed.
        return false;
    }

    // Provess keys.
    switch (e.key.keysym.sym) {
      case SDLK_LEFT: // Left
        break;
      case SDLK_RIGHT: // Right
        break;
      case SDLK_DOWN: // Down
        break;
      case SDLK_SPACE: // Rotate
        break;
    }
  }
  return true;
}
