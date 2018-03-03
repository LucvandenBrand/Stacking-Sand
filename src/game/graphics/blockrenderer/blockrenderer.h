#ifndef BLOCK_RENDERER_H
#define BLOCK_RENDERER_H

#include "blockrenderer.ih"

class BlockRenderer : public GridRenderer
{
public:
  BlockRenderer(TextureFactory &textureFactory, BlockModel &blockModel);

  void render(SDL_Renderer& sdlRenderer) override;

private:
  /* Renders a box showing the next block to fall. */
  void renderNextBlock(SDL_Renderer& sdlRenderer);
  const int SHADOW_SPREAD = 50;
  const SDL_Color SHADOW_COLOR = {0, 0, 0, 50};
  ShadowBrush d_shadowBrush;

  /* Image describing the controls. */
  Texture *d_controlImage;

  BlockModel *d_blockModel;
};

#endif /* BLOCK_RENDERER_H */
