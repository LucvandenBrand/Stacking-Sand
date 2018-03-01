#ifndef GAME_OVER_RENDERER_H
#define GAME_OVER_RENDERER_H

#include "gameoverrenderer.ih"

class GameOverRenderer: public GameRenderer
{
public:
  GameOverRenderer(TextureFactory &textureFactory, GameOverModel *gameOverModel);

  void render(SDL_Renderer &sdlRenderer) override;

private:
  GameOverModel *d_gameOverModel;
  Texture *d_gameOverTexture, *d_gameOverControls;
};

#endif /* GAME_OVER_RENDERER_H */