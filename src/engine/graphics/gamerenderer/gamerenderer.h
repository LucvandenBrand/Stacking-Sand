#ifndef GAMERENDERER_H
#define GAMERENDERER_H

#include "gamerenderer.ih"

/**
 * Renderer for a game model.
 */
class GameRenderer
{
public:
  /**
   * Abstract method for rendering a state to the screen.
   */
  virtual void render(SDL_Renderer &sdlRenderer, double deltaTime) = 0;
};

#endif // GAMERENDERER_H
