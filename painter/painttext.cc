#include "painter.ih"

void Painter::paintText(TTF_Font* font, string text, Point2D offset, SDL_Color color)
{
  try
  {
    Texture* score = new Texture(this->d_renderer, font, text, color);
    score->render(this->d_renderer, offset.x, offset.y);
    delete score;
  }
  catch(runtime_error runerr)
  {
    cout << "Could not create texture: " << runerr.what() << endl;
  }
}
