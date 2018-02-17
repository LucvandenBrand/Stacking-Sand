#include "texturefactory.ih"

Texture &TextureFactory::fontTexture(string text, TTF_Font &font, SDL_Color textColor)
{
  // Create surface and render text.
  SDL_Surface *textSurface = NULL;
  textSurface = TTF_RenderText_Solid(&font, text.c_str(), textColor);
  if (textSurface == NULL)
    throw runtime_error(SDL_GetError());

  // Create texture from surface.
  SDL_Texture *sdlTexture = NULL;
  sdlTexture = SDL_CreateTextureFromSurface(this->d_renderer, textSurface);
  if (sdlTexture == NULL)
    throw runtime_error(SDL_GetError());

  int width = textSurface->w;
  int height = textSurface->h;

  // Free surface.
  SDL_FreeSurface(textSurface);

  return *(new Texture(sdlTexture, width, height));
}
