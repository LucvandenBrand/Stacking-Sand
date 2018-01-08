#ifndef TETRIS_H
#define  TETRIS_H

#include "tetris.ih"

class Tetris
{
private:
  Grid* d_grid;
  TetrisMachine* d_tetrisMachine;
  TetrisBlock* d_tetrisBlock;

  // Scheduling var
  int d_goalTicks;

  // Calculate how long it takes for the next step to happen.
  int waitTicks();

public:
  Tetris();
  ~Tetris();

  // Return a copy of the grid in use.
  Grid grid();

  // Return a copy of the tetrisMachine in use.
  TetrisMachine tetrisMachine();

  // Return a copy of the tetris block.
  TetrisBlock* tetrisBlock();

  // Update tbe tetrismachine and block.
  void step();
};

#endif
