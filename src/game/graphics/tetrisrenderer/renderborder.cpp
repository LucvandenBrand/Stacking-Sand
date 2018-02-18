#include "tetrisrenderer.ih"

void TetrisRenderer::renderBorder(SDL_Renderer &sdlRenderer, SDL_Color color, int start, int end, int height)
{
  // Determine the direction.
  int distance = end-start;
  int step = 1;
  if (distance < 0)
  {
    step = -1;
    distance *= -1;
  }
  int alphaStep = color.a / distance;

  // Draw the lines
  for (int x = start, a = 0; x != end; x += step, a += alphaStep)
  {
    SDL_SetRenderDrawColor(&sdlRenderer, color.r, color.g, color.b, a);
    SDL_RenderDrawLine(&sdlRenderer, x, 0, x, height);
  }
  SDL_SetRenderDrawColor(&sdlRenderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawLine(&sdlRenderer, end, 0, end, height);
}
