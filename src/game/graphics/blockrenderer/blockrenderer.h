#ifndef BLOCK_RENDERER_H
#define BLOCK_RENDERER_H

#include "blockrenderer.ih"

/**
 * Renderer for a block model.
 */
class BlockRenderer : public GridRenderer
{
public:
  /**
   * Construct the renderer.
   */
  BlockRenderer(TextureFactory &textureFactory, BlockModel &blockModel);

  /**
   * Render the block model.
   */
  void render(SDL_Renderer& sdlRenderer, double deltaTime) override;

private:
  // Renders a box showing the next block to fall.
  void renderNextBlock(SDL_Renderer& sdlRenderer);
  const int SHADOW_SPREAD = 50;
  const SDL_Color SHADOW_COLOR = {0, 0, 0, 50};
  ShadowBrush d_shadowBrush;

  // Image describing the controls.
  shared_ptr<Texture> d_controlImage;

  BlockModel *d_blockModel;
};

#endif // BLOCK_RENDERER_H
