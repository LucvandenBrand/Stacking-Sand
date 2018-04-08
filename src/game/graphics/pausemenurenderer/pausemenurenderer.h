#ifndef PAUSE_MENU_RENDERER_H
#define PAUSE_MENU_RENDERER_H

#include "pausemenurenderer.ih"

class PauseMenuRenderer : public GameRenderer
{
public:
  explicit PauseMenuRenderer(TextureFactory &textureFactory, PauseMenuModel &pauseMenuModel);

  /* Render either the start screen, pause screen, or nothing. */
  void render(SDL_Renderer &sdlRenderer, double deltaTime) override;

private:
  /* Renders an animated title screen. */
  void renderStart(SDL_Renderer &sdlRenderer, double deltaTime);

  /* Renders the screen dark with a pause symbol if the game is paused. */
  void renderPause(SDL_Renderer &sdlRenderer, double deltaTime);

  PauseMenuModel *d_pauseMenuModel;
  shared_ptr<Texture> d_gameTitle, d_startControls;
  LerpSeries d_titleAnimation;

};

#endif /* PAUSE_MENU_RENDERER_H */
