#include "painter.ih"

void Painter::paint()
{
  // Clear the screen to a black background.
  SDL_SetRenderDrawColor(this->d_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(this->d_renderer);

  // Retrieve the tetris grid and calculate the size of one block.
  Grid currentGrid = this->d_tetris->grid();
  unsigned short cellSize = this->c_SCREEN_HEIGHT / currentGrid.height();

  // Paint the main grid and tetris block.
  this->paintGrid(currentGrid, cellSize);

  Grid currentBlock = this->d_tetris->tetrisBlock()->currentBlock();
  Point2D currentBlockPos = this->d_tetris->tetrisBlock()->position();
  this->paintGrid(currentBlock, cellSize, currentBlockPos);

  // Draw the score.
  string score = to_string(this->d_tetris->tetrisMachine().score());
  this->paintText(score, Point2D(0, 0));

  // Update the surface (flip buffers).
  SDL_RenderPresent(this->d_renderer);
}
