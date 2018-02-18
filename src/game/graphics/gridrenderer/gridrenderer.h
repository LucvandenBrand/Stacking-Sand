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
};

#endif /* GRID_RENDERER_H */
