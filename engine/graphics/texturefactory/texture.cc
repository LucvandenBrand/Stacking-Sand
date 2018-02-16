#include "texturefactory.ih"

Texture &TextureFactory::texture(string texturePath)
{
  if (this->d_textureCache.count(texturePath) == 0)
  { // Texture is new, try to load it.
    SDL_Texture *sdlTexture = NULL;
    SDL_Surface *surface = IMG_Load(texturePath.c_str());

    if (surface == NULL)  // Loading the image failed.
      throw invalid_argument(IMG_GetError());
    else
    { // Load was succesful, create an sdlTexture.
      sdlTexture = SDL_CreateTextureFromSurface(this->d_renderer, surface);
      SDL_FreeSurface(surface);

      if (sdlTexture == NULL)  // Creating the sdlTexture failed.
        throw runtime_error(SDL_GetError());
    }

    /* Creating the sdlTexture was succesful,
     *retrieve dimensions and store it. */
    int width, height;
    SDL_QueryTexture(sdlTexture, NULL, NULL, &width, &height);
    this->d_textureCache.emplace(texturePath, *(new Texture(sdlTexture, width, height)));
  }

  return this->d_textureCache.at(texturePath);
}
