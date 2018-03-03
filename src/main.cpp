#include "main.ih"

int main(int argc, char **argv)
{
  try
  {
    // Initialize our window.
    Window &window            = Window::getWindow();
    SDL_Renderer &sdlRenderer = window.sdlRenderer();
    TextureFactory textureFactory(&sdlRenderer);

    // Initialise our games.
    TetrisModel          tetrisModel;
    TetrisRenderer       tetrisRenderer(textureFactory, tetrisModel);
    TetrisInputParser    tetrisInputParser(tetrisModel);
    Game                 tetrisGame(tetrisRenderer, tetrisInputParser, tetrisModel);

    BlockModel           blockModel(tetrisModel);
    BlockRenderer        blockRenderer(textureFactory, blockModel);
    BlockInputParser     blockInputParser(blockModel);
    Game                 blockGame(blockRenderer, blockInputParser, blockModel);

    LevelModel           levelModel(tetrisModel);
    LevelRenderer        levelRenderer(textureFactory, levelModel);
    KillInputParser      killInputParser(levelModel);
    Game                 levelGame(levelRenderer, killInputParser, levelModel);

    GameOverModel        gameOverModel(tetrisModel, blockModel);
    GameOverRenderer     gameOverRenderer(textureFactory, gameOverModel);
    GameOverInputParser  gameOverInputParser(gameOverModel);
    Game                 gameOverGame(gameOverRenderer, gameOverInputParser, gameOverModel);

    PauseMenuModel       pauseMenuModel({&tetrisModel, &blockModel}, gameOverModel);
    PauseMenuRenderer    pauseMenuRenderer(textureFactory, pauseMenuModel);
    PauseMenuInputParser pauseMenuInputParser(pauseMenuModel);
    Game                 pauseMenuGame(pauseMenuRenderer, pauseMenuInputParser, pauseMenuModel);


    // Push the games on the game stack, following their drawing order.
    vector<Game> games;
    games.reserve(5);
    games.push_back(tetrisGame);
    games.push_back(blockGame);
    games.push_back(levelGame);
    games.push_back(pauseMenuGame);
    games.push_back(gameOverGame);

    // Main game loop
    GameLoop::loop(games, sdlRenderer);
  }
  catch(runtime_error &runtimeError)
  {
    cout << "ERROR - Could not initialize an SDL window: " << runtimeError.what() << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
