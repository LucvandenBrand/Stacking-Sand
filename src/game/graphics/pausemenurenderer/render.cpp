#include "pausemenurenderer.ih"

void PauseMenuRenderer::render(SDL_Renderer &sdlRenderer, double deltaTime)
{
  if (d_pauseMenuModel->firstStart())
    renderStart(sdlRenderer, deltaTime);
  else if (d_pauseMenuModel->paused())
    renderPause(sdlRenderer, deltaTime);
  else // Reset all pause animations.
  {
    d_pauseButtonAnimation.reset();
  }
}

