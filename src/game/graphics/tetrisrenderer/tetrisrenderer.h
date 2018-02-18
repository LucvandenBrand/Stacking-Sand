#ifndef TETRIS_RENDERER_H
#define TETRIS_RENDERER_H

#include "tetrisrenderer.ih"

class TetrisRenderer : public GridRenderer
{
public:
  TetrisRenderer(TextureFactory &textureFactory, TetrisModel *tetrisModel);

  void render(SDL_Renderer &sdlRenderer) override;

private:
  /* Fills the screen with the backgroundTile. Buffers the result for efficiency.*/
  void renderBackground(SDL_Renderer &sdlRenderer, int tileSize);

  /* Draws the points for each cell. */
  void renderLegend(SDL_Renderer &sdlRenderer, int tileSize);

  /* Draws a smooth vertical line of color. */
  void renderBorder(SDL_Renderer &sdlRenderer, SDL_Color color, int start, int end, int height);

  TetrisModel *d_tetrisModel;

  /* Used to draw the background. */
  const int SCALE_BACKGROUND_TILE = 4, SHADOW_SPREAD = 50;
  const SDL_Color BG_COLOR = {0, 0, 0, 50};
  Texture *d_background, *d_backgroundTile;
  ShadowBrush d_shadowBrush;
};

#endif /* TETRIS_RENDERER_H */
