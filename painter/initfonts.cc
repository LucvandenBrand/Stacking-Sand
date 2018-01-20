#include "painter.ih"

bool Painter::initFonts()
{
  if (TTF_Init() == -1)
    return false;

  // All fonts used in the game.
  this->d_gameFont = TTF_OpenFont("data/gameFont.ttf", 48);
  this->d_largeGameFont = TTF_OpenFont("data/gameFont.ttf", 86);

  return this->d_gameFont      != NULL &&
         this->d_largeGameFont != NULL;
}
