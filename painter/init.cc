#include "painter.ih"

bool Painter::init()
{
  // Initialize the SDL library
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return false;

  // Create a window.
  this->d_window = SDL_CreateWindow(this->c_TITLE,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    this->c_SCREEN_WIDTH,
                                    this->c_SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
  if (this->d_window == NULL)
    return false;

  // Create a renderer.
  this->d_renderer = SDL_CreateRenderer(this->d_window, -1,
                                        SDL_RENDERER_ACCELERATED);
  if (this->d_renderer == NULL)
    return false;

  // Initialize renderer and IMG library.
  SDL_SetRenderDrawColor(this->d_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  int imgFlags = IMG_INIT_PNG;
	if( !(IMG_Init(imgFlags) & imgFlags))
    return false;

  // Load fonts.
  if (TTF_Init() == -1)
    return false;

  this->d_gameFont = TTF_OpenFont("data/gameFont.ttf", 48);
  this->d_largeGameFont = TTF_OpenFont("data/gameFont.ttf", 86);
  if (this->d_gameFont == NULL || this->d_largeGameFont == NULL)
    return false;

  // Try to load the textures.
  try
  {
    // Block textures
    this->d_sandTexture = new Texture(this->d_renderer, "data/sand.png");
    this->d_dirtTexture = new Texture(this->d_renderer, "data/dirt.png");

    // Make TetrisGrid texture to draw on.
    Grid tetrisGrid = this->d_tetris->grid();
    int gridHeightRatio = this->c_SCREEN_HEIGHT / tetrisGrid.height();
    int gridWidth = gridHeightRatio * tetrisGrid.width();
    this->d_gridTexture = new Texture(this->d_renderer, gridWidth,
                                      this->c_SCREEN_HEIGHT,
                                      SDL_TEXTUREACCESS_TARGET);
  }
  catch (invalid_argument invarg)
  {
    cout << "Could not load texture: " << invarg.what() << endl;
    return false;
  }
  catch(runtime_error runerr)
  {
    cout << "Could not create texture: " << runerr.what() << endl;
    return false;
  }

  SDL_SetWindowFullscreen(this->d_window, SDL_WINDOW_FULLSCREEN);

  // Everything went fine, return success.
  return true;
}
