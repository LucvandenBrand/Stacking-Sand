#include "gameloop.ih"

void GameLoop::loop(vector<Game> &games, SDL_Renderer &sdlRenderer)
{
  auto startTime = chrono::high_resolution_clock::now();
  auto endTime = startTime;
  while(games.size())
  {
    // Calculate elapsed time.
    startTime = endTime;
    endTime = chrono::high_resolution_clock::now();
    chrono::duration<float> elapsedSeconds = endTime - startTime;
    float deltaTime = elapsedSeconds.count();

    // Destroy all dead games.
    games.erase(remove_if(games.begin(), games.end(),
                [](Game game){return !(game.alive());}),
                games.end());

    // Update all living games.
    SDL_RenderClear(&sdlRenderer);
    ButtonState buttonState = Input::getState();
    for (Game &game : games)
    {
      game.update(sdlRenderer, buttonState, deltaTime);
    }
    SDL_RenderPresent(&sdlRenderer);

    // Lock the game at MAX_DELTA_TIME to save power.
    float leftTime = MAX_DELTA_TIME - deltaTime;
    if (leftTime > 0)
      SDL_Delay((unsigned int)(MILLI_IN_SECONDS * leftTime));
  }
}
