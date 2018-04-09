#ifndef PAUSE_MENU_RENDERER_H
#define PAUSE_MENU_RENDERER_H

#include "pausemenurenderer.ih"

class PauseMenuRenderer : public GameRenderer
{
public:
  PauseMenuRenderer(TextureFactory &textureFactory, PauseMenuModel &pauseMenuModel);
  ~PauseMenuRenderer();

  /* Render either the start screen, pause screen, or nothing. */
  void render(SDL_Renderer &sdlRenderer, double deltaTime) override;

private:
  /* Renders an animated title screen. */
  void renderStart(SDL_Renderer &sdlRenderer, double deltaTime);

  /* Renders the screen dark with a pause symbol if the game is paused. */
  void renderPause(SDL_Renderer &sdlRenderer, double deltaTime);

  /* Animation constants. */
  const double ANIM_WIGGLE = 0.005, ANIM_STRETCH = 0.03;

  PauseMenuModel *d_pauseMenuModel;
  shared_ptr<Texture> d_gameTitle, d_startControls, d_credits;
  LerpSeries d_titleAnimation, d_startButtonAnimation, d_pauseButtonAnimation;
  TTF_Font* d_creditFont;
};

#endif /* PAUSE_MENU_RENDERER_H */
