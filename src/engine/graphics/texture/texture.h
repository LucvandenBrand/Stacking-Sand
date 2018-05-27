#ifndef TEXTURE_H
#define TEXTURE_H

#include "texture.ih"

/**
 * An image to be rendered on the screen.
 */
class Texture
{
public:
  /**
   * Construct a texture from an SDL texture.
   */
  Texture(SDL_Texture *texture, int width, int height);

  /**
   * Free texture memory.
   */
  ~Texture();

  /**
   * Render to a surface with a destination rectangle.
   */
  void render(SDL_Renderer &renderer, SDL_Rect destRect);

  /**
   * Render to a surface at (x, y).
   */
  void render(SDL_Renderer &renderer, int x, int y);

  /**
   * Set as render target.
   */
  void asRenderTarget(SDL_Renderer *renderer);

  /**
   * Return texture width.
   */
  int width();

  /**
   * Return texture height.
   */
  int height();

private:
  // The hardware texture.
  SDL_Texture *d_texture;

  // Texture size.
  int d_width;
  int d_height;
};

#endif // TEXTURE_H
