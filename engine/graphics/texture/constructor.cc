#include "texture.ih"

Texture::Texture(SDL_Renderer* renderer, string texturePath)
{
  SDL_Texture* texture = NULL;
  SDL_Surface* surface = IMG_Load(texturePath.c_str());

  if (surface == NULL)  // Loading the image failed.
    throw invalid_argument(IMG_GetError());
  else
  { // Load was succesful, create a texture.
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (texture == NULL)  // Creating the texture failed.
      throw runtime_error(SDL_GetError());
  }

  /* Creating the texture was succesful,
   *retrieve dimensions and store it. */
  SDL_QueryTexture(texture, NULL, NULL, &(this->d_width), &(this->d_height));
  this->d_texture = texture;
}
