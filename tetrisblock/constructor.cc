#include "tetrisblock.ih"

TetrisBlock::TetrisBlock(Grid* tetrisGrid) : d_tetrisGrid(tetrisGrid)
{
  // Define a line block.
  Grid lineBlock(1, 3);
  *(lineBlock.cell(Point2D(0,0))) = 4;
  *(lineBlock.cell(Point2D(0,1))) = 4;
  *(lineBlock.cell(Point2D(0,2))) = 4;
  this->d_blocks.push_back(lineBlock);

  // Define an L block.
  Grid lBlock(2, 3);
  *(lBlock.cell(Point2D(0,0))) = 4;
  *(lBlock.cell(Point2D(0,1))) = 4;
  *(lBlock.cell(Point2D(0,2))) = 4;
  *(lBlock.cell(Point2D(1,2))) = 4;
  this->d_blocks.push_back(lBlock);

  // Initialise random seed.
  srand (time(NULL));

  // Set initial state.
  reset();
}
