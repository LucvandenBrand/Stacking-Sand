#ifndef PAUSE_MENU_RENDERER_H
#define PAUSE_MENU_RENDERER_H

#include "pausemenurenderer.ih"

/**
 * Renders the pause menu model.
 */
class PauseMenuRenderer : public GameRenderer
{
public:
  /**
   * Construct the renderer.
   */
  PauseMenuRenderer(TextureFactory &textureFactory, PauseMenuModel &pauseMenuModel);

  /**
   * Free memory allocated by the renderer.
   */
  ~PauseMenuRenderer();

  /**
   * Render either the start screen, pause screen, or nothing.
   */
  void render(SDL_Renderer &sdlRenderer, double deltaTime) override;

private:
  // Renders an animated title screen.
  void renderStart(SDL_Renderer &sdlRenderer, double deltaTime);

  // Renders the screen dark with a pause symbol if the game is paused.
  void renderPause(SDL_Renderer &sdlRenderer, double deltaTime);

  // Animation constants.
  const double ANIM_WIGGLE = 0.005, ANIM_STRETCH = 0.03;

  PauseMenuModel *d_pauseMenuModel;
  shared_ptr<Texture> d_gameTitle, d_startControls;
  LerpSeries d_titleAnimation, d_startButtonAnimation, d_pauseButtonAnimation;
  TTF_Font* d_creditFont;
};

#endif // PAUSE_MENU_RENDERER_H
