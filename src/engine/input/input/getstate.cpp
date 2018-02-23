#include "input.ih"

InputState Input::getState()
{
  SDL_Event e;
  InputState inputState = {0, 0};
  ButtonState buttonState = 0;
  while(SDL_PollEvent(&e) != 0)
  {
    // Process keys.
    switch (e.key.keysym.sym)
    {
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

    switch (e.type)
    {
      case (SDL_KEYUP):
        inputState.upButtons |= buttonState;
        break;
      case (SDL_KEYDOWN):
        inputState.downButtons |= buttonState;
        break;
    }
  }
  return inputState;
}
