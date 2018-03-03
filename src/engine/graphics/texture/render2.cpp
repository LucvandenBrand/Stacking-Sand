#include "texture.ih"

void Texture::render(SDL_Renderer &renderer, int x, int y)
{
  SDL_Rect destRect;
  destRect.x = x;
  destRect.y = y;
  destRect.w = d_width;
  destRect.h = d_height;

  render(renderer, destRect);
}
