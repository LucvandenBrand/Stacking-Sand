#include "painter.ih"

void Painter::paint()
{
  // Clear the screen to a black background.
  this->d_gridTexture->asRenderTarget(this->d_renderer);
  SDL_SetRenderDrawColor(this->d_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(this->d_renderer);

  // Retrieve the tetris grid and calculate the size of one block.
  Grid currentGrid = this->d_tetris->grid();
  unsigned short cellSize = this->d_gridTexture->height() / currentGrid.height();

  // Paint the main grid and tetris block.
  this->paintGrid(currentGrid, cellSize);

  Grid currentBlock = this->d_tetris->tetrisBlock()->currentBlock();
  Point2D currentBlockPos = this->d_tetris->tetrisBlock()->position();
  this->paintGrid(currentBlock, cellSize, currentBlockPos);

  SDL_SetRenderTarget(this->d_renderer, NULL);
  int mid = this->c_SCREEN_WIDTH/2 - this->d_gridTexture->width()/2;
  this->d_gridTexture->render(this->d_renderer, mid, 0);

  // Draw the score.
  string score = to_string(this->d_tetris->tetrisMachine().score());
  this->paintText(score, Point2D(0, 0));

  // Update the surface (flip buffers).
  SDL_RenderPresent(this->d_renderer);
}
