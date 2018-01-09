#include "texture.ih"

void Texture::render(SDL_Renderer* renderer, int x, int y)
{
  SDL_Rect sourceRect;
  sourceRect.x = 0;
  sourceRect.y = 0;
  sourceRect.w = this->d_width;
  sourceRect.h = this->d_height;

  SDL_Rect destRect;
  destRect.x = x;
  destRect.y = y;
  destRect.w = this->d_width;
  destRect.h = this->d_height;

  SDL_RenderCopy(renderer, this->d_texture, &sourceRect, &destRect);
}
