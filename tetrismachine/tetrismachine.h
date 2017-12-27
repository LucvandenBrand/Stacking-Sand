#ifndef TETRISMACHINE_H
#define TETRISMACHINE_H

#include "tetrismachine.ih"

class TetrisMachine
{
private:
  Grid* d_grid;
  unsigned int d_score;

public:
  TetrisMachine(Grid* grid);

  // Return the current score.
  unsigned int score();

  // Step to the next state of the grid.
  void step();
};

#endif // TETRISMACHINE_H
