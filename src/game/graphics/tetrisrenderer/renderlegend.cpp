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
  Texture *title = textureFactory.fontTexture("Worth", *d_gameFont, fontColor);

  // Draw Title
  float titleWidth  = legendW * 0.5f;
  float titleHeight = titleWidth / normalizer.normalizeWidth(title->width())
                      * normalizer.normalizeHeight(title->height());
  float titleX      = legendX + legendW / 2 - titleWidth / 2;
  float titleY      = legendY + 0.01f;

  SDL_Rect titleRectangle = normalizer.deNormalize(titleX, titleY, titleWidth, titleHeight);
  title->render(sdlRenderer, titleRectangle);
  delete title;

  // Determine cell value positions.
  float paddingHeight = 0.06f;
  unsigned long numCells = d_cellTextures.size();
  float cellHeight = (legendH - titleHeight) / numCells - (numCells/2+0.5f) * paddingHeight;
  float cellWidth  = cellHeight * normalizer.ratio();


  for (int i=0; i < numCells; i++)
  {
    // Draw the cell.
    float cellX = legendX + legendW / 2 - cellWidth / 2;
    float cellY = paddingHeight + legendY + titleHeight + i * (cellHeight + paddingHeight);
    SDL_Rect cellRectangle = normalizer.deNormalize(cellX, cellY, cellWidth, cellHeight);
    d_shadowBrush.drawRectangle(sdlRenderer, cellRectangle);
    this->d_cellTextures[i].render(sdlRenderer, cellRectangle);

    // Render value textures.
    string value = "$" + to_string(i+1);
    fontColor = {0, 0, 0, 150};
    Texture *valueTextBG = textureFactory.fontTexture(value, *d_gameFont, fontColor);
    fontColor = {100, 200, 100, 255};
    Texture *valueText = textureFactory.fontTexture(value, *d_gameFont, fontColor);

    // Determine value position.
    float valueWidth  = cellWidth * 0.5f;
    float valueHeight = valueWidth / normalizer.normalizeWidth(valueText->width())
                                  * normalizer.normalizeHeight(valueText->height());
    float valueY = cellY + cellHeight - valueHeight / 2;
    float valueX = cellX + cellWidth  - valueWidth / 2;

    // Render value (background shadow and front).
    SDL_Rect valueBGRectangle = normalizer.deNormalize(valueX, valueY+0.005f, valueWidth, valueHeight);
    valueTextBG->render(sdlRenderer, valueBGRectangle);
    SDL_Rect valueRectangle = normalizer.deNormalize(valueX, valueY, valueWidth, valueHeight);
    valueText->render(sdlRenderer, valueRectangle);

    delete valueText, valueTextBG;
  }
}
