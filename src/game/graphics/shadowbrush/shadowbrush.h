#ifndef SHADOW_BRUSH_H
#define SHADOW_BRUSH_H

#include  "shadowbrush.ih"

/**
 * Utility renderer that renders a shadow rectangle.
 */
class ShadowBrush
{
public:
  /**
   * Construct a shadow brush of a particular color an shadow spread.
   */
  ShadowBrush(SDL_Color color, int spread);

  /**
   * Draws a shadow rectangle.
   */
  void drawRectangle(SDL_Renderer &renderer, SDL_Rect rectangle);

private:
  SDL_Color d_color;
  int d_spread;
};

#endif // SHADOW_BRUSH_H
