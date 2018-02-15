#ifndef GAMERENDERER_H
#define GAMERENDERER_H

#include "gamerenderer.ih"

class GameRenderer
{
public:
  virtual void render(SDL_Renderer &sdlRenderer) = 0;
};

#endif /* GAMERENDERER_H */
