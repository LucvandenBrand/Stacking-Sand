#include "texture.ih"

Texture::~Texture()
{
  SDL_DestroyTexture(d_texture);
}
