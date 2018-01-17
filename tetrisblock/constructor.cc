#include "tetrisblock.ih"

TetrisBlock::TetrisBlock(Grid* tetrisGrid) : d_tetrisGrid(tetrisGrid)
{
  // Define a line block.
  Grid lineBlock(1, 3);
  *(lineBlock.cell(Point2D(0,0))) = 3;
  *(lineBlock.cell(Point2D(0,1))) = 1;
  *(lineBlock.cell(Point2D(0,2))) = 4;
  this->d_blocks.push_back(lineBlock);

  // Define an L block.
  Grid lBlock(2, 3);
  *(lBlock.cell(Point2D(0,0))) = 4;
  *(lBlock.cell(Point2D(0,1))) = 3;
  *(lBlock.cell(Point2D(0,2))) = 1;
  *(lBlock.cell(Point2D(1,2))) = 4;
  this->d_blocks.push_back(lBlock);

  // Define a triangle
  Grid tBlock(3, 2);
  *(tBlock.cell(Point2D(0,1))) = 4;
  *(tBlock.cell(Point2D(1,1))) = 3;
  *(tBlock.cell(Point2D(1,0))) = 4;
  *(tBlock.cell(Point2D(2,1))) = 1;
  this->d_blocks.push_back(tBlock);

  // Define a square
  Grid sBlock(2, 2);
  *(sBlock.cell(Point2D(0,0))) = 4;
  *(sBlock.cell(Point2D(1,0))) = 3;
  *(sBlock.cell(Point2D(0,1))) = 3;
  *(sBlock.cell(Point2D(1,1))) = 4;
  this->d_blocks.push_back(sBlock);

  // Initialise random seed.
  srand (time(NULL));

  // Initialize the first block (by setting the next block, see reset),
  this->d_nextBlockIndex = rand() % this->d_blocks.size();

  // Set initial state.
  reset();
}
