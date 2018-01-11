#ifndef TEXTURE_H
#define TEXTURE_H

#include "texture.ih"

class Texture
{
public:
  Texture(SDL_Renderer* renderer, string texturePath);
  ~Texture();

  // Render to a surface.
  void render(SDL_Renderer* renderer, SDL_Rect destRect);
  void render(SDL_Renderer* renderer, int x, int y);

  // Return texture size.
  int width();
  int height();

private:
  // The hardware texture.
  SDL_Texture* d_texture;

  // Texture size.
  int d_width;
  int d_height;
};

#endif /* TEXTURE_H */
