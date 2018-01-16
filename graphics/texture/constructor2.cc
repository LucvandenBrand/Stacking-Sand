#include "texture.ih"

Texture::Texture(SDL_Renderer* renderer, int width, int height,
                 SDL_TextureAccess access)
{
  SDL_Texture* texture = NULL;
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                              access, width, height);

  if (texture == NULL)  // Creating the texture failed.
    throw runtime_error(SDL_GetError());

  this->d_texture = texture;

  /* Creating the texture was succesful, store dimensions. */
  this->d_width = width;
  this->d_height = height;
}
