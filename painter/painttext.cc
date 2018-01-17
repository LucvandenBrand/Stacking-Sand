#include "painter.ih"

void Painter::paintText(string text, Point2D offset, SDL_Color color)
{
  try
  {
    Texture* score = new Texture(this->d_renderer, this->d_gameFont, text, color);
    score->render(this->d_renderer, offset.x, offset.y);
    delete score;
  }
  catch(runtime_error runerr)
  {
    cout << "Could not create texture: " << runerr.what() << endl;
  }
}
