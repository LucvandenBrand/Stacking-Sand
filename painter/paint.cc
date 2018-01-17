#include "painter.ih"

void Painter::paint()
{
  // Clear the screen to a black background.
  SDL_SetRenderDrawColor(this->d_renderer, 0, 0, 0, 0xFF);
  SDL_RenderClear(this->d_renderer);

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
  this->paintGrid(currentBlock, cellSize, currentBlockPos * cellSize);

  SDL_SetRenderTarget(this->d_renderer, NULL);
  int mid = this->c_SCREEN_WIDTH/2 - this->d_gridTexture->width()/2;
  this->d_gridTexture->render(this->d_renderer, mid, 0);

  // Draw the 'Next Block' window.
  SDL_Color textColor = {255, 255, 255, 255};
  this->paintText(this->d_gameFont, "Next material:", Point2D(40, 20), textColor);

  Grid nextBlock = this->d_tetris->tetrisBlock()->nextBlock();
  Point2D nextBlockPos(220 - nextBlock.width()*cellSize/2, 100);
  this->paintGrid(nextBlock, cellSize, nextBlockPos);

  // Draw the score.
  int offset = this->c_SCREEN_WIDTH * (2.0 / 3.0) + 20;
  string score = "$ " + to_string(this->d_tetris->tetrisMachine().score());
  this->paintText(this->d_largeGameFont, score, Point2D(offset, 20), textColor);

  // Update the surface (flip buffers).
  SDL_RenderPresent(this->d_renderer);
}
