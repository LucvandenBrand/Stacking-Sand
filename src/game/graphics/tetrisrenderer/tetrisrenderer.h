#ifndef TETRIS_RENDERER_H
#define TETRIS_RENDERER_H

#include "tetrisrenderer.ih"

class TetrisRenderer : public GridRenderer
{
public:
  TetrisRenderer(TextureFactory &textureFactory, TetrisModel &tetrisModel);
  ~TetrisRenderer();

  void render(SDL_Renderer &sdlRenderer, double deltaTime) override;

private:
  /* Fills the screen with the backgroundTile. Buffers the result for efficiency.*/
  void renderBackground(SDL_Renderer &sdlRenderer, int tileSize);

  /* Draws the current score. */
  void renderScore(SDL_Renderer &sdlRenderer);

  /* Draws the points for each cell. */
  void renderLegend(SDL_Renderer &sdlRenderer);

  TetrisModel *d_tetrisModel;

  /* The font of the game. */
  TTF_Font* d_gameFont;

  /* Used to draw the background. */
  const int SCALE_BACKGROUND_TILE = 4, SHADOW_SPREAD = 50;
  const SDL_Color BG_COLOR = {0, 0, 0, 50};
  unique_ptr<Texture> d_background;
  shared_ptr<Texture> d_backgroundTile;
  ShadowBrush d_shadowBrush;

  /* Constants for the legend. */
  const int LEGEND_COLS = 2;
};

#endif /* TETRIS_RENDERER_H */
