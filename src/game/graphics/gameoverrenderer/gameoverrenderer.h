#ifndef GAME_OVER_RENDERER_H
#define GAME_OVER_RENDERER_H

#include "gameoverrenderer.ih"

class GameOverRenderer: public GameRenderer
{
public:
  GameOverRenderer(GameOverModel *gameOverModel);

  void render(SDL_Renderer &sdlRenderer) override;

private:
  GameOverModel *d_gameOverModel;
};

#endif /* GAME_OVER_RENDERER_H */