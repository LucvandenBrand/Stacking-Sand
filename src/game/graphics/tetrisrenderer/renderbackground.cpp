#include "tetrisrenderer.ih"

void TetrisRenderer::renderBackground(SDL_Renderer &sdlRenderer, int tileSize)
{
  int renderWidth = 0, renderHeight = 0;
  SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);
  if (renderWidth != d_background->width() || renderHeight != d_background->height())
  { // Screen size has changed, redraw the background.
    delete d_background;
    d_background = TextureFactory(&sdlRenderer).renderTexture(renderWidth, renderHeight);
    d_background->asRenderTarget(&sdlRenderer);
    for (int x = 0; x < renderWidth; x += tileSize)
      for (int y = 0; y < renderHeight; y += tileSize)
      {
        SDL_Rect rectangle = {x, y, tileSize, tileSize};
        d_backgroundTile->render(sdlRenderer, rectangle);
      }
    SDL_SetRenderTarget(&sdlRenderer, nullptr);
  }
  d_background->render(sdlRenderer, 0, 0);
}
