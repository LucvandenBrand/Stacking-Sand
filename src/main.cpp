#include "main.ih"

int main(int argc, char **argv)
{
  try
  {
    // Initialize our window.
    Window &window = Window::getWindow();
    SDL_Renderer &sdlRenderer = window.sdlRenderer();
    TextureFactory textureFactory(&sdlRenderer);

    // Initialise our games.
    auto *tetrisModel          = new TetrisModel();
    auto *tetrisRenderer       = new TetrisRenderer(textureFactory, tetrisModel);
    auto *tetrisInputParser    = new TetrisInputParser(tetrisModel);
    auto *tetrisGame           = new Game(tetrisRenderer, tetrisInputParser, tetrisModel);

    auto *blockModel           = new BlockModel(tetrisModel);
    auto *blockRenderer        = new BlockRenderer(textureFactory, blockModel);
    auto *blockInputParser     = new BlockInputParser(blockModel);
    auto *blockGame            = new Game(blockRenderer, blockInputParser, blockModel);

    auto *levelModel           = new LevelModel(tetrisModel);
    auto *levelRenderer        = new LevelRenderer(textureFactory, levelModel);
    auto *killInputParser      = new KillInputParser(levelModel);
    auto *levelGame            = new Game(levelRenderer, killInputParser, levelModel);

    auto *pauseMenuModel       = new PauseMenuModel({tetrisModel, blockModel});
    auto *pauseMenuRenderer    = new PauseMenuRenderer(pauseMenuModel);
    auto *pauseMenuInputParser = new PauseMenuInputParser(pauseMenuModel);
    auto *pauseMenuGame        = new Game(pauseMenuRenderer, pauseMenuInputParser, pauseMenuModel);


    // Push the games on the game stack, following their drawing order.
    vector<Game> games;
    games.reserve(3);
    games.push_back(*tetrisGame);
    games.push_back(*blockGame);
    games.push_back(*levelGame);
    games.push_back(*pauseMenuGame);

    // Main game loop
    GameLoop::loop(games, sdlRenderer);

    // Free our games.
    delete tetrisModel;
    delete tetrisRenderer;
    delete tetrisInputParser;
    delete tetrisGame;

    delete blockModel;
    delete blockRenderer;
    delete blockInputParser;
    delete blockGame;

    delete levelModel;
    delete levelRenderer;
    delete killInputParser;
    delete levelGame;

    delete pauseMenuModel;
    delete pauseMenuRenderer;
    delete pauseMenuInputParser;
    delete pauseMenuGame;
  }
  catch(runtime_error &runtimeError)
  {
    cout << "ERROR - Could not initialize an SDL window: " << runtimeError.what() << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
