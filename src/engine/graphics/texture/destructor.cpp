#include "texture.ih"

Texture::~Texture()
{
  SDL_DestroyTexture(this->d_texture);
}
