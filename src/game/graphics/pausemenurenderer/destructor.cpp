#include "pausemenurenderer.ih"

PauseMenuRenderer::~PauseMenuRenderer()
{
  TTF_CloseFont(d_creditFont);
}