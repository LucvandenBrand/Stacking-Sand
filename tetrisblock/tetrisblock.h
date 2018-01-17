#ifndef TETRISBLOCK_H
#define TETRISBLOCK_H

#include "tetrisblock.ih"

class TetrisBlock
{
private:
  Grid* d_tetrisGrid;
  vector<Grid> d_blocks;
  unsigned short d_currentBlockIndex, d_nextBlockIndex;
  Point2D d_position, d_move;

  // Copy source onto destination at d_position.
  void stamp();

  // Check if this block overlaps with the tetrisGrid at position.
  bool overlap(Point2D newPosition);

  // Choose stamp and position.
  void reset();

public:
  TetrisBlock(Grid* tetrisGrid);

  // Set the moving direction.
  void move(Point2D shift);

  // Return the current position.
  Point2D position();

  // return the current or next block in use.
  Grid currentBlock();
  Grid nextBlock();

  // Update the state.
  void step();
};

#endif // TETRISBLOCK_H
