#ifndef PAUSE_MENU_RENDERER_H
#define PAUSE_MENU_RENDERER_H

#include "pausemenurenderer.ih"

class PauseMenuRenderer : public GameRenderer
{
public:
  explicit PauseMenuRenderer(PauseMenuModel *pauseMenuModel);

  /* Renders the screen dark with a pause symbol if the game is paused. */
  void render(SDL_Renderer &sdlRenderer) override;

private:
  PauseMenuModel *d_pauseMenuModel;
};

#endif /* PAUSE_MENU_RENDERER_H */
