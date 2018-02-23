#include "game.ih"

void Game::update(SDL_Renderer& sdlRenderer, InputState inputState, float deltaTime)
{
  d_inputParser->parse(inputState);
  d_model->step(deltaTime);
  d_renderer->render(sdlRenderer);
}
