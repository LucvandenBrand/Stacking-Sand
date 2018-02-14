#include "input.ih"

ButtonState Input::getState()
{
  SDL_Event e;
  ButtonState buttonState = 0;
  while(SDL_PollEvent(&e) != 0)
  {
    // Process keys.
    switch (e.key.keysym.sym) {
      case SDLK_LEFT: // Left
        buttonState |= LEFT;
        break;
      case SDLK_RIGHT: // Right
        buttonState |= RIGHT;
        break;
      case SDLK_DOWN: // Down
        buttonState |= DOWN;
        break;
      case SDLK_SPACE: // Start
        buttonState |= START;
        break;
      case SDLK_ESCAPE: // Escape
        buttonState |= ESCAPE;
        break;
    }
  }
  return buttonState;
}
