#include "game.ih"

void Game::update(SDL_Renderer& sdlRenderer, ButtonState buttonState, float deltaTime)
{
  d_inputParser->parse(buttonState);
  d_model->step(deltaTime);
  d_renderer->render(sdlRenderer);
}
