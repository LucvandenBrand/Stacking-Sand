#include "texture.ih"

void Texture::render(SDL_Renderer* renderer, int x, int y)
{
  SDL_Rect destRect;
  destRect.x = x;
  destRect.y = y;
  destRect.w = this->d_width;
  destRect.h = this->d_height;

  this->render(renderer, destRect);
}
