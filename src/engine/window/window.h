#ifndef WINDOW_H
#define WINDOW_H

#include "window.ih"

/**
 * Singleton class that represents the game window.
 */
class Window
{
public:
  // This is a singleton, so we do not want copying.
  Window(Window const&)         = delete;
  void operator=(Window const&) = delete;

  /**
   * Return the static instance.
   */
  static Window &getWindow();

  /**
   * Destructor, deletes SDL objects and closes SDL subsystems.
   */
  ~Window();

  /**
   * Return the sdl renderer to draw with.
   */
  SDL_Renderer &sdlRenderer();

private:
  Window();

  // Start SDL and create an SDL window, return success state.
  bool init();

  const char *c_TITLE = "TinyTetris";
  const int c_SCREEN_WIDTH  = 1920;
  const int c_SCREEN_HEIGHT = 1080;

  // Draw objects.
  SDL_Window *d_window = nullptr;
  SDL_Renderer *d_renderer = nullptr;
};

#endif // WINDOW_H
