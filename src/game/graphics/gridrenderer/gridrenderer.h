#ifndef GRID_RENDERER_H
#define GRID_RENDERER_H

#include "gridrenderer.ih"

/* Class that renders a Grid. */
class GridRenderer: public GameRenderer
{
public:
  explicit GridRenderer(TextureFactory &textureFactory);
  ~GridRenderer();

  virtual void render(SDL_Renderer &sdlRenderer) = 0;

protected:
  void renderGrid(SDL_Renderer &sdlRenderer, Grid grid, SDL_Rect rectangle);
  vector<Texture> d_cellTextures;

private:
  /* Initializes all grid textures used to render. */
  bool initTextures(TextureFactory &textureFactory);

  /* Shadow of each block. */
  const int SHADOW_SPREAD = 5;
  const SDL_Color SHADOW_COLOR = {0, 0, 0, 25};
};

#endif /* GRID_RENDERER_H */
