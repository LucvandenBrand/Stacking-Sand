#ifndef TEXTURE_FACTORY_H
#define TEXTURE_FACTORY_H

#include "texturefactory.ih"

/**
 * Generator for textures.
 */
class TextureFactory {
public:
  /**
   * Construct a texture factory.
   */
  explicit TextureFactory(SDL_Renderer *sdlRenderer);

  /**
   * Free allocated memory for the factory.
   */
  ~TextureFactory();

  /**
   * Loads textures if not loaded yet and returns a handle for them.
   */
  shared_ptr<Texture> texture(string texturePath);

  /**
   * Returns a texture that can be rendered-to.
   */
  unique_ptr<Texture> renderTexture(int width, int height,
                        SDL_TextureAccess = SDL_TEXTUREACCESS_TARGET);

  /**
   * Render a font and return it as a texture.
   */
  unique_ptr<Texture> fontTexture(string text, TTF_Font &font, SDL_Color textColor);

private:
  SDL_Renderer *d_renderer;

  // Hash-map of all textures loaded.
  map<string, shared_ptr<Texture>> d_textureCache;
};

#endif // TEXTURE_FACTORY_H
