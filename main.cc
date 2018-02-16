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
    TetrisModel *tetrisModel = new TetrisModel();
    TetrisRenderer *tetrisRenderer = new TetrisRenderer(textureFactory, tetrisModel);
    TetrisInputParser *tetrisInputParser = new TetrisInputParser(tetrisModel);
    Game *tetrisGame = new Game(tetrisRenderer, tetrisInputParser, tetrisModel);

    BlockModel *blockModel = new BlockModel(tetrisModel);
    BlockRenderer *blockRenderer = new BlockRenderer(textureFactory, blockModel);
    BlockInputParser *blockInputParser = new BlockInputParser(blockModel);
    Game *blockGame = new Game(blockRenderer, blockInputParser, blockModel);

    // Push the games on the game stack, following their drawing order.
    vector<Game> games;
    games.reserve(2);
    games.push_back(*blockGame);
    games.push_back(*tetrisGame);

    // Main game loop
    GameLoop::loop(games, sdlRenderer);
  }
  catch(runtime_error runerr)
  {
    cout << "ERROR - Could not initialize an SDL window: " << runerr.what() << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
