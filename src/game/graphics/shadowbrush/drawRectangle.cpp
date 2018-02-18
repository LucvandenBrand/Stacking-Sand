#include "shadowbrush.ih"

void ShadowBrush::drawRectangle(SDL_Renderer &renderer, SDL_Rect rectangle)
{
  int alphaStep = this->d_color.a / this->d_spread;
  for (int i = 0, a = this->d_color.a; i < this->d_spread; ++i, a -= alphaStep)
  {
    SDL_Rect drawRectangle = rectangle;
    drawRectangle.h += i;
    drawRectangle.w += i;
    drawRectangle.x -= i/2;
    drawRectangle.y -= i/2;
    SDL_SetRenderDrawColor(&renderer, this->d_color.r, this->d_color.g, this->d_color.b, a);
    SDL_RenderDrawRect(&renderer, &drawRectangle);
  }
  SDL_SetRenderDrawColor(&renderer, this->d_color.r, this->d_color.g, this->d_color.b, this->d_color.a);
  SDL_RenderFillRect(&renderer, &rectangle);
}
