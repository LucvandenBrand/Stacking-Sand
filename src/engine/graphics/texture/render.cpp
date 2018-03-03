#include "texture.ih"

void Texture::render(SDL_Renderer &renderer, SDL_Rect destRect)
{
  SDL_Rect sourceRect;
  sourceRect.x = 0;
  sourceRect.y = 0;
  sourceRect.w = d_width;
  sourceRect.h = d_height;

  SDL_RenderCopy(&renderer, d_texture, &sourceRect, &destRect);
}
