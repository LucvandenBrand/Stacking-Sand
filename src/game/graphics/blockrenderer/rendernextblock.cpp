#include "blockrenderer.ih"

void BlockRenderer::renderNextBlock(SDL_Renderer &sdlRenderer)
{
  ScreenNormalizer normalizer(sdlRenderer);

  // Draw the containing shadow rectangle.
  float boxX      = 0.225;
  float boxY      = 0.015;
  float boxWidth  = 0.115;
  float boxHeight = 0.2;
  SDL_Rect boxRectangle = normalizer.deNormalize(boxX, boxY, boxWidth, boxHeight);
  d_shadowBrush.drawRectangle(sdlRenderer, boxRectangle);

  // Draw the next block.
  Grid blockGrid    = d_blockModel->nextBlock();
  float cellHeight  = boxHeight * 0.6f / blockGrid.height();
  float cellWidth   = cellHeight * normalizer.ratio();
  float blockWidth  = blockGrid.width()  * cellWidth;
  float blockHeight = blockGrid.height() * cellHeight;
  float blockX      = boxX + boxWidth  / 2 - blockWidth / 2;
  float blockY      = boxY + boxHeight / 2 - blockHeight / 2;
  SDL_Rect blockRectangle = normalizer.deNormalize(blockX, blockY, blockWidth, blockHeight);
  renderGrid(sdlRenderer, blockGrid, blockRectangle);

  // Draw the controls of the game.
  float controlPosX   = 0.02;
  float controlWidth  = boxX - 2 * controlPosX;
  float controlHeight = controlWidth / normalizer.normalizeWidth(d_controlImage->width())
                       * normalizer.normalizeHeight(d_controlImage->height());
  float controlPosY   = boxY + boxHeight / 2.0f - controlHeight / 2.0f;
  SDL_Rect controlRectangle = normalizer.deNormalize(controlPosX, controlPosY, controlWidth, controlHeight);
  d_controlImage->render(sdlRenderer, controlRectangle);
}
