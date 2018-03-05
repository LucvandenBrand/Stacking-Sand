#include "gameloop.ih"

void GameLoop::loop(vector<Model*> models, vector<InputParser*> inputParsers,
                    vector<GameRenderer*> gameRenderers)
{
  d_running = true;

  // Spawn the model update thread.
  thread modelThread(&GameLoop::loopModels, this, models);

  // Whilst running, process input and draw.
  Window &window            = Window::getWindow();
  SDL_Renderer &sdlRenderer = window.sdlRenderer();
  while(d_running)
  {
    parseInput(inputParsers);
    render(gameRenderers, sdlRenderer);
    this_thread::sleep_for(chrono::milliseconds(UPDATE_SPEED_MAIN));
  }

  // Running is done, join the model thread and exit.
  modelThread.join();
}