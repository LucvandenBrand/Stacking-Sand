#ifndef TETRISBLOCK_H
#define TETRISBLOCK_H

#include "tetrisblock.ih"

class TetrisBlock
{
private:
  Grid* d_tetrisGrid;
  vector<Grid> d_blocks;
  unsigned short d_currentBlockIndex;
  Point2D d_position, d_move;

  // Copy source onto destination at position.
  //void stamp()

  // Choose stamp and position.
  void reset();

public:
  TetrisBlock(Grid* tetrisGrid);

  //void move(Point2D shift);
  //Point2D position();
  //Grid currentBlock();
  void step();
};

#endif // TETRISBLOCK_H
