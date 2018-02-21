#include "tetrisrenderer.ih"

void TetrisRenderer::renderScore(SDL_Renderer &sdlRenderer)
{
  // Draw the containing shadow rectangle.
  int renderWidth = 0, renderHeight = 0;
  SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);
  auto boxX      = (int) (renderWidth  * 0.65);
  auto boxY      = (int) (renderHeight * 0.01);
  auto boxWidth  = (int) (renderWidth  * 0.34);
  auto boxHeight = (int) (renderHeight * 0.2);
  SDL_Rect boxRectangle = {boxX, boxY, boxWidth, boxHeight};
  this->d_shadowBrush.drawRectangle(sdlRenderer, boxRectangle);

  // Try to load font.
  TTF_Font* font = nullptr;
  font = TTF_OpenFont("data/gameFont.ttf", 80);
  if (font == nullptr)
  {
    cout << "Failed to load gameFont!" << '\n';
    return;
  }

  // Prepare text.
  SDL_Color fontColor = {100, 200, 100, 255};
  TextureFactory textureFactory(&sdlRenderer);
  char scoreString[25];
  sprintf(scoreString, "$ %06d", this->d_tetrisModel->score());
  Texture *score = textureFactory.fontTexture(scoreString, *font, fontColor);

  // Draw Title
  auto scoreWidth = (int) (boxWidth * 0.9);
  int scoreHeight = scoreWidth / score->width() * score->height();
  int scoreX      = boxX + boxWidth / 2 - scoreWidth / 2;
  int scoreY      = boxY + boxHeight / 2 - scoreHeight / 2;

  SDL_Rect titleRectangle = {scoreX, scoreY, scoreWidth, scoreHeight};
  score->render(sdlRenderer, titleRectangle);
  delete score;
}