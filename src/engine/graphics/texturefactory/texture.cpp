#include "texturefactory.ih"

Texture &TextureFactory::texture(string texturePath)
{
  if (d_textureCache.count(texturePath) == 0)
  { // Texture is new, try to load it.
    SDL_Texture *sdlTexture = nullptr;
    SDL_Surface *surface = IMG_Load(texturePath.c_str());

    if (!surface)  // Loading the image failed.
      throw invalid_argument(IMG_GetError());
    else
    { // Load was successful, create an sdlTexture.
      sdlTexture = SDL_CreateTextureFromSurface(d_renderer, surface);
      SDL_FreeSurface(surface);

      if (!sdlTexture)  // Creating the sdlTexture failed.
        throw runtime_error(SDL_GetError());
    }

    /* Creating the sdlTexture was successful,
     * retrieve dimensions and store it. */
    int width, height;
    SDL_QueryTexture(sdlTexture, nullptr, nullptr, &width, &height);
    d_textureCache.emplace(texturePath, *(new Texture(sdlTexture, width, height)));
  }

  return d_textureCache.at(texturePath);
}
