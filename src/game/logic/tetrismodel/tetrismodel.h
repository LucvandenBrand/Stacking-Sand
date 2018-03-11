#ifndef TETRIS_MACHINE_H
#define TETRIS_MACHINE_H

#include "tetrismodel.ih"

class TetrisModel : public Model, public Pauseble
{
public:
  TetrisModel();
  ~TetrisModel();

  // Return the current score.
  unsigned int score();

  // Return the highest score recorded.
  unsigned int highScore();

  // Load and save the hi-score.
  void updateHighScore();

  // Return the current level.
  unsigned int level();

  // Return the time left to wait.
  double timeToWait();

  // Step to the next state of the grid.
  void step(double deltaTime) override;

  // Return a copy of the grid used.
  Grid grid();

  // Initialize the grid and set the score to 0.
  void reset();

  // Copy source onto destination at d_position.
  void stamp(Grid fromGrid, Point2D position);

private:
  /* Game and studio name for saving. */
  const char* NAME_COMPANY = "VanDenBrand";
  const char* NAME_PRODUCT = "StackingSandWithBillBigsby";
  const char* NAME_SAVE    = "highScore.txt";

  /* Game-play constants. */
  const int TETRIS_WIDTH = 10;
  const int TETRIS_HEIGHT = 20;

  const double       DELAY_LEVEL0 = 0.4;
  const unsigned int SCORE_LEVEL1 = 10;
  const double       DELAY_LEVEL1 = 0.2;
  const unsigned int SCORE_LEVEL2 = 50;
  const double       DELAY_LEVEL2 = 0.1;
  const unsigned int SCORE_LEVEL3 = 100;
  const double       DELAY_LEVEL3 = 0.05;
  const unsigned int SCORE_LEVEL4 = 200;
  const double       DELAY_LEVEL4 = 0.02;
  const unsigned int SCORE_LEVEL5 = 300;
  const double       DELAY_LEVEL5 = 0.01;
  const unsigned int SCORE_LEVEL6 = 400;
  const double       DELAY_LEVEL6 = 0.005;

  const short STONE = 2;
  const short PRESSURE_STONE = 2;
  const short DIAMOND = 3;
  const short PRESSURE_DIAMOND = 5;

  /* The grid the game is played on. */
  Grid d_grid;

  /* The amount of points won. */
  unsigned int d_score, d_highScore;

  // Scheduling var
  double d_timeToWait;

  // Change cells into other cells depending on the pressure.
  void applyPressure(Point2D point);

  // Calculate how long it takes for the next step to happen.
  double waitTime();
};

#endif // TETRIS_MACHINE_H
