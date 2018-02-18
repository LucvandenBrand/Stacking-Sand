#include "tetrisrenderer.ih"

void TetrisRenderer::renderBackground(SDL_Renderer &sdlRenderer, int tileSize)
{
  int renderWidth = 0, renderHeight = 0;
  SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);
  if (renderWidth != this->d_background->width() || renderHeight != this->d_background->height())
  { // Screen size has changed, redraw the background.
    delete this->d_background;
    this->d_background = TextureFactory(&sdlRenderer).renderTexture(renderWidth, renderHeight);
    this->d_background->asRenderTarget(&sdlRenderer);
    for (int x = 0; x < renderWidth; x += tileSize)
      for (int y = 0; y < renderHeight; y += tileSize)
      {
        SDL_Rect rectangle = {x, y, tileSize, tileSize};
        this->d_backgroundTile->render(sdlRenderer, rectangle);
      }
    SDL_SetRenderTarget(&sdlRenderer, nullptr);
  }
  this->d_background->render(sdlRenderer, 0, 0);
}
