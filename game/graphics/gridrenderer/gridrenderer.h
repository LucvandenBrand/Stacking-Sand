#ifndef GRIDRENDERER_H
#define GRIDRENDERER_H

#include "gridrenderer.ih"

/* Class that renderes a Grid. */
class GridRenderer: public GameRenderer
{
public:
  GridRenderer(TextureFactory &textureFactory);
  ~GridRenderer();

  virtual void render(SDL_Renderer &sdlRenderer) = 0;

protected:
  void renderGrid(SDL_Renderer &sdlRenderer, Grid grid, Point2D size,
                  Point2D offset);

private:
  /* Initializes all grid textures used to render. */
  bool initTextures(TextureFactory &textureFactory);

  vector<Texture> d_cellTextures;
};

#endif /* GRIDRENDERER_H */
