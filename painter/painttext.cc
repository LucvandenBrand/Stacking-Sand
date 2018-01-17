#include "painter.ih"

void Painter::paintText(TTF_Font* font, string text, Point2D offset,
                        SDL_Color color, bool centered)
{
  try
  {
    Texture* score = new Texture(this->d_renderer, font, text, color);

    // If the text is supposed to be centered, detract half its width.
    if (centered)
      offset.x -= score->width() / 2;

    score->render(this->d_renderer, offset.x, offset.y);
    delete score;
  }
  catch(runtime_error runerr)
  {
    cout << "Could not create texture: " << runerr.what() << endl;
  }
}
