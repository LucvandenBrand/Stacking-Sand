#ifndef TEXTURE_FACTORY_H
#define TEXTURE_FACTORY_H

#include "texturefactory.ih"

class TextureFactory {
public:
  explicit TextureFactory(SDL_Renderer *sdlRenderer);
  ~TextureFactory();

  /* Loads textures if not loaded yet and returns a handle for them. */
  Texture &texture(string texturePath);

  /* Returns a texture that can be rendered-to. */
  Texture *renderTexture(int width, int height,
                        SDL_TextureAccess = SDL_TEXTUREACCESS_TARGET);

  /* Render a font and return it as a texture. */
  Texture *fontTexture(string text, TTF_Font &font, SDL_Color textColor);

private:
  SDL_Renderer *d_renderer;

  /* Hash-map of all textures loaded. */
  map<string, Texture&> d_textureCache;
};

#endif /* TEXTURE_FACTORY_H */
