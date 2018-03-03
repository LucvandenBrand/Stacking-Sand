#include "texture.ih"

void Texture::asRenderTarget(SDL_Renderer *renderer)
{
  SDL_SetRenderTarget(renderer, d_texture);
}
