#ifndef PAINTER_H
#define PAINTER_H

#include "painter.ih"

class Painter
{
private:
  const char* c_TITLE = "TinyTetris";
  const int c_SCREEN_WIDTH = 480;
  const int c_SCREEN_HEIGHT = 640;

  Tetris* d_tetris;
  SDL_Window* d_window = NULL;
  SDL_Surface* d_screenSurface = NULL;

public:
  Painter(Tetris* tetris);

  // Destructor, deletes SDL objects and closes SDL subsystems.
  ~Painter();

  // Paints the tetris state to the surface of the SDL window.
  void paint();

  // Start SDL and create window, return success state.
  bool init();
};

#endif // PAINTER_H
