#ifndef BLOCKRENDERER_H
#define BLOCKRENDERER_H

#include "blockrenderer.ih"

class BlockRenderer : public GridRenderer
{
public:
  BlockRenderer(SDL_Renderer *sdlRenderer, BlockModel *blockModel);
  ~BlockRenderer();

  void render(SDL_Renderer& sdlRenderer);

private:
  BlockModel *d_blockModel;
};

#endif /* BLOCKRENDERER_H */
