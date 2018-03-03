#include "blockrenderer.ih"

void BlockRenderer::render(SDL_Renderer &sdlRenderer)
{
  ScreenNormalizer normalizer(sdlRenderer);
  Grid grid = d_blockModel->grid();

  // Determine the tetris grid size.
  float cellHeight  = 1.0f / grid.height();
  float cellWidth   = cellHeight * normalizer.ratio();
  float gridWidth   = cellWidth * grid.width();

  // Determine the block position and size.
  Grid blockGrid    = d_blockModel->currentBlock();
  Point2D position  = d_blockModel->position();
  float blockX      = 0.5f - gridWidth / 2 + position.x * cellWidth;
  float blockY      = position.y * cellHeight;
  float blockWidth  = blockGrid.width() * cellWidth;
  float blockHeight = blockGrid.height() * cellHeight;

  // Render the current block.
  SDL_Rect rectangle = normalizer.deNormalize(blockX, blockY, blockWidth, blockHeight);
  renderGrid(sdlRenderer, blockGrid, rectangle);

  // Render the next block.
  renderNextBlock(sdlRenderer);
}
