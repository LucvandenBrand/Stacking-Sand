#include "texture.ih"

Texture::Texture(SDL_Renderer &renderer, TTF_Font &font, string text,
                 SDL_Color textColor)
{
  // Create surface and render text.
  SDL_Surface *textSurface = NULL;
  textSurface = TTF_RenderText_Solid(&font, text.c_str(), textColor);
  if (textSurface == NULL)
    throw runtime_error(SDL_GetError());

  // Create texture from surface.
  SDL_Texture *texture = NULL;
  texture = SDL_CreateTextureFromSurface(&renderer, textSurface);
  if (texture == NULL)
    throw runtime_error(SDL_GetError());

  this->d_texture = texture;
  this->d_width = textSurface->w;
  this->d_height = textSurface->h;

  // Free surface.
  SDL_FreeSurface(textSurface);
}
