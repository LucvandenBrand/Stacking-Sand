#ifndef SHADOW_BRUSH_H
#define SHADOW_BRUSH_H

#include  "shadowbrush.ih"

class ShadowBrush
{
public:
  ShadowBrush(SDL_Color color, int spread);

  /* Draws a shadow rectangle. */
  void drawRectangle(SDL_Renderer &renderer, SDL_Rect rectangle);

private:
SDL_Color d_color;
int d_spread;
};

#endif /* SHADOW_BRUSH_H */
