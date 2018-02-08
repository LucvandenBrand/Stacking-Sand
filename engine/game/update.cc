#include "game.ih"

void Game::update(Window& window, ButtonState buttonState, float deltaTime)
{
  d_inputParser->parse(buttonState);
  d_model->step(deltaTime);
  d_renderer->render(window);
}
