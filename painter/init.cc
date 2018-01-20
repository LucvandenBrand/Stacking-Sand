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
  if (!initFonts())
    return false;

  // Try to load the textures.
  if (!initTextures())
    return false;

  SDL_SetWindowFullscreen(this->d_window, SDL_WINDOW_FULLSCREEN);

  // Everything went fine, return success.
  return true;
}
