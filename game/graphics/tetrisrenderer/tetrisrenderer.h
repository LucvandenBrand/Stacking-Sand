#ifndef TETRISRENDERER_H
#define TETRISRENDERER_H

#include "tetrisrenderer.ih"

class TetrisRenderer : public GridRenderer
{
public:
  TetrisRenderer(SDL_Renderer *sdlRenderer, TetrisModel *tetrisModel);
  ~TetrisRenderer();

  void render(SDL_Renderer& sdlRenderer);

private:
  TetrisModel *d_tetrisModel;
};

#endif /* TETRISRENDERER_H */
