#ifndef PAINTER_H
#define PAINTER_H

#include "painter.ih"

class Painter
{
private:
  const char* c_TITLE = "TinyTetris";
  const int c_SCREEN_WIDTH = 1920;
  const int c_SCREEN_HEIGHT = 1080;

  // Game mode
  Tetris* d_tetris;

  // Draw objects.
  SDL_Window* d_window = NULL;
  SDL_Renderer* d_renderer = NULL;

  // Font to draw with.
  TTF_Font* d_gameFont = NULL;
  TTF_Font* d_largeGameFont = NULL;

  // Used Textures
  Texture *d_sandTexture, *d_dirtTexture;
  Texture *d_gridTexture;

  // Draw the tetris grid.
  void paintGrid(Grid currentGrid, unsigned short cellSize, Point2D offset);
  void paintGrid(Grid currentGrid, unsigned short cellSize);

  // Draw some (left aligned) text on the screen.
  void paintText(TTF_Font* font, string text, Point2D offset,
                 SDL_Color color, bool centered = false);

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
