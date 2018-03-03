#include "texturefactory.ih"

Texture *TextureFactory::renderTexture(int width, int height, SDL_TextureAccess access)
{
  SDL_Texture *sdlTexture = NULL;
  sdlTexture = SDL_CreateTexture(d_renderer, SDL_PIXELFORMAT_RGBA8888,
                                 access, width, height);

  if (sdlTexture == NULL)  // Creating the texture failed.
    throw runtime_error(SDL_GetError());

  return new Texture(sdlTexture, width, height);
}
