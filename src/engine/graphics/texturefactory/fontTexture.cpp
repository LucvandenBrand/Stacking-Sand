#include "texturefactory.ih"

unique_ptr<Texture> TextureFactory::fontTexture(string text, TTF_Font &font, SDL_Color textColor)
{
  // Create surface and render text.
  SDL_Surface *textSurface = nullptr;
  textSurface = TTF_RenderText_Blended(&font, text.c_str(), textColor);
  if (!textSurface)
    throw runtime_error(SDL_GetError());

  // Create texture from surface.
  SDL_Texture *sdlTexture = nullptr;
  sdlTexture = SDL_CreateTextureFromSurface(d_renderer, textSurface);
  if (!sdlTexture)
    throw runtime_error(SDL_GetError());

  // Properly apply alpha channel.
  SDL_SetTextureAlphaMod(sdlTexture, textColor.a);

  int width = textSurface->w;
  int height = textSurface->h;

  // Free surface.
  SDL_FreeSurface(textSurface);

  return make_unique<Texture>(sdlTexture, width, height);
}
