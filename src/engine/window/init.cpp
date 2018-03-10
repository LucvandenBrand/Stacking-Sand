#include "window.ih"

bool Window::init()
{
  // Initialize the SDL library
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return false;

  // Create a window.
  d_window = SDL_CreateWindow(c_TITLE,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    c_SCREEN_WIDTH,
                                    c_SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
  if (!d_window)
    return false;

  // Create a renderer.
  d_renderer = SDL_CreateRenderer(d_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!d_renderer)
    return false;

  // Initialize renderer and IMG library.
  SDL_SetRenderDrawColor(d_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  int imgFlags = IMG_INIT_PNG;
	if( !(IMG_Init(imgFlags) & imgFlags))
    return false;

  // Initialize font library.
  if (TTF_Init() == -1)
    return false;

  // Initialize Mixer library
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    return false;

  // Set general settings.
  SDL_SetRenderDrawBlendMode(d_renderer, SDL_BLENDMODE_BLEND);
  SDL_SetWindowFullscreen(d_window, SDL_WINDOW_FULLSCREEN);

  // Everything went fine, return success.
  return true;
}
