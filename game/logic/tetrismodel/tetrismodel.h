#ifndef TETRISMACHINE_H
#define TETRISMACHINE_H

#include "tetrismodel.ih"

class TetrisModel : public Model
{
public:
  TetrisModel();
  ~TetrisModel();

  // Return the current score.
  unsigned int score();

  // Return the time left to wait.
  float timeToWait();

  // Step to the next state of the grid.
  void step(float deltaTime);

  // Decrease the time to wait by speedupTime.
  void speedup(float speedupTime);

  Grid* grid();

private:
  /* Gameplay constants. */
  const int TETRIS_WIDTH = 10;
  const int TETRIS_HEIGHT = 20;

  const float DELAY_LEVEL0 = 0.8;
  const unsigned int SCORE_LEVEL1 = 10;
  const float        DELAY_LEVEL1 = 0.7;
  const unsigned int SCORE_LEVEL2 = 50;
  const float        DELAY_LEVEL2 = 0.6;
  const unsigned int SCORE_LEVEL3 = 100;
  const float        DELAY_LEVEL3 = 0.5;
  const unsigned int SCORE_LEVEL4 = 200;
  const float        DELAY_LEVEL4 = 0.4;
  const unsigned int SCORE_LEVEL5 = 300;
  const float        DELAY_LEVEL5 = 0.3;
  const unsigned int SCORE_LEVEL6 = 400;
  const float        DELAY_LEVEL6 = 0.2;

  const short STONE = 2;
  const short PRESSURE_STONE = 3;

  /* The grid the game is played on. */
  Grid* d_grid;

  unsigned int d_score;

  // Scheduling var
  float d_timeToWait;

  // Change cells into other cells depending on the pressure.
  void applyPressure(Point2D point);

  // Calculate how long it takes for the next step to happen.
  float waitTime();
};

#endif // TETRISMACHINE_H
