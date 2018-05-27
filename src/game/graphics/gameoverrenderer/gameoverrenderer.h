#ifndef GAME_OVER_RENDERER_H
#define GAME_OVER_RENDERER_H

#include "gameoverrenderer.ih"

/**
 * Render the game over state.
 */
class GameOverRenderer: public GameRenderer
{
public:
  /**
   * Construct the renderer.
   */
  GameOverRenderer(TextureFactory &textureFactory, GameOverModel &gameOverModel);

  /**
   * Render the game over state.
   */
  void render(SDL_Renderer &sdlRenderer, double deltaTime) override;

private:
  GameOverModel *d_gameOverModel;
  shared_ptr<Texture> d_gameOverTexture, d_gameOverControls;
};

#endif // GAME_OVER_RENDERER_H