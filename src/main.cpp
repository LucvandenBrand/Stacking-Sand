#include "main.ih"

int main(int argc, char **argv)
{
  try
  {
    // Initialize our window.
    Window &window            = Window::getWindow();
    SDL_Renderer &sdlRenderer = window.sdlRenderer();
    TextureFactory textureFactory(&sdlRenderer);
    AudioFactory audioFactory;

    // Initialise our games.
    TetrisModel          tetrisModel;
    TetrisRenderer       tetrisRenderer(textureFactory, tetrisModel);
    TetrisInputParser    tetrisInputParser(tetrisModel);
    TetrisAudio          tetrisAudio(audioFactory, tetrisModel);

    BlockModel           blockModel(tetrisModel);
    BlockRenderer        blockRenderer(textureFactory, blockModel);
    BlockInputParser     blockInputParser(blockModel);
    BlockAudio           blockAudio(audioFactory, blockModel);

    LevelModel           levelModel(tetrisModel);
    LevelRenderer        levelRenderer(textureFactory, levelModel);
    KillInputParser      killInputParser(levelModel);
    LevelAudio           levelAudio(audioFactory, levelModel);

    GameOverModel        gameOverModel(tetrisModel, blockModel);
    GameOverRenderer     gameOverRenderer(textureFactory, gameOverModel);
    GameOverInputParser  gameOverInputParser(gameOverModel);

    PauseMenuModel       pauseMenuModel({&tetrisModel, &blockModel, &levelModel}, gameOverModel);
    PauseMenuRenderer    pauseMenuRenderer(textureFactory, pauseMenuModel);
    PauseMenuInputParser pauseMenuInputParser(pauseMenuModel);


    // Push the games on the game stack, following their drawing order.
    const unsigned int NUM_MODELS = 5;
    vector<Model*> models;
    models.reserve(NUM_MODELS);
    models.push_back(&tetrisModel);
    models.push_back(&blockModel);
    models.push_back(&levelModel);
    models.push_back(&pauseMenuModel);
    models.push_back(&gameOverModel);

    vector<InputParser*> inputParsers;
    inputParsers.reserve(NUM_MODELS);
    inputParsers.push_back(&tetrisInputParser);
    inputParsers.push_back(&blockInputParser);
    inputParsers.push_back(&killInputParser);
    inputParsers.push_back(&pauseMenuInputParser);
    inputParsers.push_back(&gameOverInputParser);

    vector<GameRenderer*> gameRenderers;
    gameRenderers.reserve(NUM_MODELS);
    gameRenderers.push_back(&tetrisRenderer);
    gameRenderers.push_back(&blockRenderer);
    gameRenderers.push_back(&levelRenderer);
    gameRenderers.push_back(&pauseMenuRenderer);
    gameRenderers.push_back(&gameOverRenderer);

    vector<GameAudio*> gameAudios;
    gameAudios.reserve(NUM_MODELS);
    gameAudios.push_back(&levelAudio);
    gameAudios.push_back(&tetrisAudio);
    gameAudios.push_back(&blockAudio);

    // Main game loop
    GameLoop gameLoop;
    gameLoop.loop(models, inputParsers, gameRenderers, gameAudios);
  }
  catch(runtime_error &runtimeError)
  {
    cout << "ERROR - Could not initialize an SDL window: " << runtimeError.what() << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
