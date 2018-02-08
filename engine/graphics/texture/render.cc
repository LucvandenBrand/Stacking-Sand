#include "texture.ih"

void Texture::render(SDL_Renderer* renderer, SDL_Rect destRect)
{
  SDL_Rect sourceRect;
  sourceRect.x = 0;
  sourceRect.y = 0;
  sourceRect.w = this->d_width;
  sourceRect.h = this->d_height;

  SDL_RenderCopy(renderer, this->d_texture, &sourceRect, &destRect);
}
