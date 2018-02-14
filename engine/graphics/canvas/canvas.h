#ifndef CANVAS_H
#define CANVAS_H

#include "canvas.ih"

class Canvas {
public:
  Canvas(SDL_Renderer &sdl_renderer);

  /* Loads textures and returns a handle for them. */
  Texture getTexture(string texturePath);
  
  Texture createRenderTexture(int width, int height, SDL_TextureAccess);
  Texture createFontTexture(TTF_Font &font, string text, SDL_Color textColor);

  // Render to a surface.
  void render(Texture &texture, SDL_Rect destRect);
  void render(Texture &texture, int x, int y);

  // Set as render target.
  void asRenderTarget(Texture &texture);


};

#endif /* CANVAS_H */
