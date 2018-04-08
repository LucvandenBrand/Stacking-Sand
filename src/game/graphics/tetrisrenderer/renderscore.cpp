#include "tetrisrenderer.ih"

void TetrisRenderer::renderScore(SDL_Renderer &sdlRenderer)
{
  ScreenNormalizer normalizer(sdlRenderer);
  // Draw the containing shadow rectangle.
  float boxX      = 0.66;
  float boxY      = 0.015;
  float boxWidth  = 0.32;
  float boxHeight = 0.2;
  SDL_Rect boxRectangle = normalizer.deNormalize(boxX, boxY, boxWidth, boxHeight);
  d_shadowBrush.drawRectangle(sdlRenderer, boxRectangle);

  // Prepare text.
  TextureFactory textureFactory(&sdlRenderer);
  char scoreString[25], highScoreString[25];
  sprintf(scoreString, "$ %06d", d_tetrisModel->score());
  sprintf(highScoreString, "Richest: $ %06d", d_tetrisModel->highScore());
  unique_ptr<Texture> scoreTexture = textureFactory.fontTexture(scoreString, *d_gameFont, {100, 200, 100, 255});
  unique_ptr<Texture> highScoreTexture = textureFactory.fontTexture(highScoreString, *d_gameFont, {80, 210, 80, 255});

  // Draw Score
  float scoreWidth  = boxWidth * 0.9f;
  float scoreHeight = scoreWidth / normalizer.normalizeWidth(scoreTexture->width())
                                 * normalizer.normalizeHeight(scoreTexture->height());
  float scoreX      = boxX + boxWidth / 2 - scoreWidth / 2;
  float scoreY      = boxY + boxHeight / 2 - scoreHeight / 2 - 0.02f;

  SDL_Rect scoreRectangle = normalizer.deNormalize(scoreX, scoreY, scoreWidth, scoreHeight);
  scoreTexture->render(sdlRenderer, scoreRectangle);

  // Draw high-score.
  scoreWidth  = boxWidth * 0.9f;
  scoreHeight = scoreWidth / normalizer.normalizeWidth(highScoreTexture->width())
                * normalizer.normalizeHeight(highScoreTexture->height());
  scoreX      = boxX + boxWidth / 2 - scoreWidth / 2;
  scoreY      = boxY + boxHeight - scoreHeight;
  scoreRectangle = normalizer.deNormalize(scoreX, scoreY, scoreWidth, scoreHeight);
  highScoreTexture->render(sdlRenderer, scoreRectangle);
}