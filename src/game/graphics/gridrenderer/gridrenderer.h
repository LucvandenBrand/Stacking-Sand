#ifndef GRID_RENDERER_H
#define GRID_RENDERER_H

#include "gridrenderer.ih"

/**
 * Abstract renderer for a grid.
 * */
class GridRenderer: public GameRenderer
{
public:
  /**
   * Construct the renderer.
   */
  explicit GridRenderer(TextureFactory &textureFactory);

  /**
   * Free allocated memory.
   */
  ~GridRenderer();

  /**
   * Abstract method for rendering a grid.
   */
  virtual void render(SDL_Renderer &sdlRenderer, double deltaTime) = 0;

protected:
  /**
   * Render the grid.
   */
  void renderGrid(SDL_Renderer &sdlRenderer, Grid grid, SDL_Rect rectangle);

  /**
   * Textures of the cells.
   */
  vector<shared_ptr<Texture>> d_cellTextures;

private:
  // Initializes all grid textures used to render.
  bool initTextures(TextureFactory &textureFactory);

  // Shadow of each block.
  const int SHADOW_SPREAD = 5;
  const SDL_Color SHADOW_COLOR = {0, 0, 0, 25};
};

#endif // GRID_RENDERER_H
