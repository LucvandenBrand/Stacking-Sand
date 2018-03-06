#include "texturefactory.ih"

unique_ptr<Texture> TextureFactory::renderTexture(int width, int height, SDL_TextureAccess access)
{
  SDL_Texture *sdlTexture = nullptr;
  sdlTexture = SDL_CreateTexture(d_renderer, SDL_PIXELFORMAT_RGBA8888,
                                 access, width, height);

  if (!sdlTexture)  // Creating the texture failed.
    throw runtime_error(SDL_GetError());

  return make_unique<Texture>(sdlTexture, width, height);
}
