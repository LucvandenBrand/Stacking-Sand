#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H

#include "texturefactory.ih"

class TextureFactory {
public:
  TextureFactory(SDL_Renderer *sdlRenderer);
  ~TextureFactory();

  /* Loads textures if not loaded yet and returns a handle for them. */
  Texture &texture(string texturePath);

  /* Returns a texture that can be rendered-to. */
  Texture &renderTexture(int width, int height,
                        SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);

  /* Render a font and return it as a texture. */
  Texture &fontTexture(string text, TTF_Font &font, SDL_Color textColor);
private:
  SDL_Renderer *d_renderer;

  /* Hashmap of all textures loaded. */
  map<string, Texture&> d_textureCache;
};

#endif /* TEXTUREFACTORY_H */
