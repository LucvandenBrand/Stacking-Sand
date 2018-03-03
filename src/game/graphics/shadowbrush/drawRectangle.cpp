#include "shadowbrush.ih"

void ShadowBrush::drawRectangle(SDL_Renderer &renderer, SDL_Rect rectangle)
{
  int alphaStep = d_color.a / d_spread;
  for (int i = 0, a = d_color.a; i < d_spread; ++i, a -= alphaStep)
  {
    SDL_Rect drawRectangle = rectangle;
    drawRectangle.h += i;
    drawRectangle.w += i;
    drawRectangle.x -= i/2;
    drawRectangle.y -= i/2;
    SDL_SetRenderDrawColor(&renderer, d_color.r, d_color.g, d_color.b, a);
    SDL_RenderDrawRect(&renderer, &drawRectangle);
  }
  SDL_SetRenderDrawColor(&renderer, d_color.r, d_color.g, d_color.b, d_color.a);
  SDL_RenderFillRect(&renderer, &rectangle);
}
