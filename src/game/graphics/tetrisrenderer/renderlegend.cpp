#include "tetrisrenderer.ih"

void TetrisRenderer::renderLegend(SDL_Renderer &sdlRenderer)
{
  ScreenNormalizer normalizer(sdlRenderer);

  // Draw the shadow box.
  float legendX = 0.02;
  float legendY = 0.245;
  float legendW = 0.32;
  float legendH = 0.74;
  SDL_Rect rectangle = normalizer.deNormalize(legendX, legendY, legendW, legendH);
  d_shadowBrush.drawRectangle(sdlRenderer, rectangle);

  // Prepare text.
  SDL_Color fontColor = {255, 255, 255, 255};
  TextureFactory textureFactory(&sdlRenderer);
  unique_ptr<Texture> title = textureFactory.fontTexture("Worth", *d_gameFont, fontColor);

  // Draw Title
  float titleWidth  = legendW * 0.5f;
  float titleHeight = titleWidth / normalizer.normalizeWidth(title->width())
                      * normalizer.normalizeHeight(title->height());
  float titleX      = legendX + legendW / 2 - titleWidth / 2;
  float titleY      = legendY + 0.01f;

  SDL_Rect titleRectangle = normalizer.deNormalize(titleX, titleY, titleWidth, titleHeight);
  title->render(sdlRenderer, titleRectangle);

  // Determine the dimensions of the table.
  unsigned long numCells = d_cellTextures.size();
  unsigned long colCells = numCells / LEGEND_COLS;

  float titlePadding = 0.05f;
  float cellPadding  = 0.05f;

  float tableHeight = legendH - titleHeight - titlePadding;
  float columnWidth = legendW / LEGEND_COLS;

  float cellHeight  = tableHeight / colCells - cellPadding;
  float cellWidth   = cellHeight * normalizer.ratio();

  for (int col = 0; col < LEGEND_COLS; col++)
  {
    int index = 0;
    for (int row = 0; row < colCells && index < numCells; row++)
    {
      index = (int) (col*colCells + row);
      // Draw the cell.
      float cellX = legendX + col * columnWidth + columnWidth / 2.f - cellWidth / 2.f;
      float cellY = titlePadding + legendY + titleHeight + row * cellHeight + row*cellPadding;
      SDL_Rect cellRectangle = normalizer.deNormalize(cellX, cellY, cellWidth, cellHeight);
      d_shadowBrush.drawRectangle(sdlRenderer, cellRectangle);
      d_cellTextures[index]->render(sdlRenderer, cellRectangle);

      // Render value textures.
      string value = "$" + to_string(d_tetrisModel->value(index));
      fontColor = {0, 0, 0, 150};
      unique_ptr<Texture> valueTextBG = textureFactory.fontTexture(value, *d_gameFont, fontColor);
      fontColor = {100, 200, 100, 255};
      unique_ptr<Texture> valueText = textureFactory.fontTexture(value, *d_gameFont, fontColor);

      // Determine value position.
      float valueWidth  = cellWidth * 0.5f;
      float valueHeight = valueWidth / normalizer.normalizeWidth(valueText->width())
                          * normalizer.normalizeHeight(valueText->height());
      float valueY = cellY + cellHeight - valueHeight / 2;
      float valueX = cellX + cellWidth / 2  - valueWidth / 2;

      // Render value (background shadow and front).
      SDL_Rect valueBGRectangle = normalizer.deNormalize(valueX, valueY+0.005f, valueWidth, valueHeight);
      valueTextBG->render(sdlRenderer, valueBGRectangle);
      SDL_Rect valueRectangle = normalizer.deNormalize(valueX, valueY, valueWidth, valueHeight);
      valueText->render(sdlRenderer, valueRectangle);
    }
  }
}
