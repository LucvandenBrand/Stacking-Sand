#ifndef TETRIS_H
#define  TETRIS_H

#include "tetris.ih"

class Tetris
{
private:
  /* Gameplay constants. */
  const int TETRIS_WIDTH = 10;
  const int TETRIS_HEIGHT = 20;

  const unsigned int SPEED_LEVEL0 = 150000;
  const unsigned int SCORE_LEVEL1 = 10, SPEED_LEVEL1 = 130000;
  const unsigned int SCORE_LEVEL2 = 50, SPEED_LEVEL2 = 120000;
  const unsigned int SCORE_LEVEL3 = 100, SPEED_LEVEL3 = 110000;
  const unsigned int SCORE_LEVEL4 = 200, SPEED_LEVEL4 = 100000;
  const unsigned int SCORE_LEVEL5 = 300, SPEED_LEVEL5 = 90000;
  const unsigned int SCORE_LEVEL6 = 400, SPEED_LEVEL6 = 60000;

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

  // Decrease the goalTicks by time.
  void speedup(int speedupTime);
};

#endif
