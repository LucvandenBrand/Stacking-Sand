#ifndef TETRISMACHINE_H
#define TETRISMACHINE_H

#include "tetrismachine.ih"

class TetrisMachine
{
private:
  /* Gameplay constants. */
  const short STONE = 2;
  const short PRESSURE_STONE = 3;

  Grid* d_grid;
  unsigned int d_score;

  void applyPressure(Point2D point);

public:
  TetrisMachine(Grid* grid);

  // Return the current score.
  unsigned int score();

  // Step to the next state of the grid.
  void step();
};

#endif // TETRISMACHINE_H
