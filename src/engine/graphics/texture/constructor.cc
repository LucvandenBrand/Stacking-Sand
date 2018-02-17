#include "texture.ih"

Texture::Texture(SDL_Texture *texture, int width, int height)
  : d_texture(texture), d_width(width), d_height(height)
{}
