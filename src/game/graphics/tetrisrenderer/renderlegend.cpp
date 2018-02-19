#include "tetrisrenderer.ih"

void TetrisRenderer::renderLegend(SDL_Renderer &sdlRenderer, int cellSize)
{
  int renderWidth = 0, renderHeight = 0;
  SDL_GetRendererOutputSize(&sdlRenderer, &renderWidth, &renderHeight);

  // Draw the shadow box.
  auto legendX = (int) (renderWidth * 0.02);
  auto legendY = (int) (renderHeight * 0.5);
  auto legendW = (int) (renderWidth * 0.32);
  auto legendH = (int) (renderHeight * 0.48);
  SDL_Rect rectangle = {legendX, legendY, legendW, legendH};
  this->d_shadowBrush.drawRectangle(sdlRenderer, rectangle);

  // Try to load font.
  TTF_Font* font = nullptr;
  font = TTF_OpenFont("data/gameFont.ttf", 80);
  if (font == nullptr)
  {
    cout << "Failed to load gameFont!" << '\n';
    return;
  }

  // Prepare text.
  SDL_Color fontColor = {255, 255, 255, 255};
  TextureFactory textureFactory(&sdlRenderer);
  Texture *title = textureFactory.fontTexture("Worth", *font, fontColor);
  Texture *valueSand = textureFactory.fontTexture("Sand is 1$", *font, fontColor);
  Texture *valueStone = textureFactory.fontTexture("Stone is 2$", *font, fontColor);
  Texture *valueDiamond = textureFactory.fontTexture("Diamond is 3$", *font, fontColor);

  // Draw Title
  auto titleWidth = (int) (legendW * 0.5);
  int titleHeight = titleWidth / title->width() * title->height();
  int titleX      = legendX + legendW / 2 - titleWidth / 2;

  SDL_Rect titleRectangle = {titleX, legendY, titleWidth, titleHeight};
  title->render(sdlRenderer, titleRectangle);
  delete title;

  // Determine cell value positions.
  auto cellX = (int) (legendX + legendW * 0.1);
  auto cellY = (int) (legendY + legendH * 0.3);
  auto valueWidth = (int) (1.0 * cellSize / valueSand->height() * valueSand->width());
  auto valueMaxWidth = legendW - (cellX - legendX + cellSize);
  int valueX = (cellX + cellSize) + valueMaxWidth / 2 - valueWidth / 2;

  // Draw the cells and their values.
  SDL_Rect cellRectangle = {cellX, cellY, cellSize, cellSize};
  this->d_cellTextures[0].render(sdlRenderer, cellRectangle);
  SDL_Rect valueRectangle = {valueX, cellY, valueWidth, cellSize};
  valueSand->render(sdlRenderer, valueRectangle);
  delete valueSand;

  cellRectangle.y += renderHeight * 0.1;
  valueRectangle.y = cellRectangle.y;
  this->d_cellTextures[1].render(sdlRenderer, cellRectangle);
  valueStone->render(sdlRenderer, valueRectangle);
  delete valueStone;

  cellRectangle.y += renderHeight * 0.1;
  valueRectangle.y = cellRectangle.y;
  this->d_cellTextures[2].render(sdlRenderer, cellRectangle);
  valueDiamond->render(sdlRenderer, valueRectangle);
  delete valueDiamond;

}
