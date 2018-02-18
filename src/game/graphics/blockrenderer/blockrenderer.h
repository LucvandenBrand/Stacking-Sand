#ifndef BLOCK_RENDERER_H
#define BLOCK_RENDERER_H

#include "blockrenderer.ih"

class BlockRenderer : public GridRenderer
{
public:
  BlockRenderer(TextureFactory &textureFactory, BlockModel *blockModel);

  void render(SDL_Renderer& sdlRenderer) override;

private:
  BlockModel *d_blockModel;
};

#endif /* BLOCK_RENDERER_H */
