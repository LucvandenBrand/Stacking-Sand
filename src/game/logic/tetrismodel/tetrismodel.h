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

  // Return the value of cell.
  int value(int cell);

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

  // Semantic names for each cell index and their count.
  static const short NUM_CELLS = 9;
  const short AIR = 0;
  const short SAND = 1;
  const short STONE = 2;
  const short DIAMOND = 3;
  const short PLANT = 4;
  const short COAL = 5;
  const short LAVA = 6;
  const short GLASS = 7;
  const short COAL_FIRE = 8;
  const short ICE = 9;

  // Number of levels in the game.
  static const short NUM_LEVELS = 14;

private:
  /* Game and studio name for saving. */
  const char* NAME_COMPANY = "VanDenBrand";
  const char* NAME_PRODUCT = "StackingSandWithBillBigsby";
  const char* NAME_SAVE    = "highScore.txt";

  /* Game-play constants. */
  const int TETRIS_WIDTH = 10;
  const int TETRIS_HEIGHT = 20;

  const double   DELAY_LEVEL[NUM_LEVELS] = {0.5, 0.4, 0.35, 0.32, 0.30, 0.28, 0.25, 0.22, 0.20, 0.18, 0.15,  0.12, 0.100, 0.050};
  const unsigned SCORE_LEVEL[NUM_LEVELS] = {  0, 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000};

  const short WEIGHT[NUM_CELLS] = {1 , 1,   1, 1,  1, 1,  1,  1,  1};
  const short HEAT[NUM_CELLS]   = {0 , 0,   0, 0,  0, 1,  0,  1, -2};
  const short VALUE[NUM_CELLS]  = {1 , 5, 100, 5, 50, 5, 30, 15,  5};

  const short PRESSURE_SAND_TO_STONE   = 5;
  const short PRESSURE_COAL_TO_DIAMOND = 8;
  const short PRESSURE_PLANT_TO_COAL   = 3;
  const short PRESSURE_GLASS_TO_AIR    = 2;

  const short HEAT_SAND_TO_GLASS     =  1;
  const short HEAT_COAL_TO_COAL_FIRE =  1;
  const short HEAT_ICE_TO_PLANT      =  1;
  const short HEAT_LAVA_TO_STONE     = -1;

  /* The grid the game is played on. */
  Grid d_grid;

  /* The amount of points won. */
  unsigned int d_score, d_highScore;

  // Scheduling var
  double d_timeToWait;

  // Change cells into other cells depending on the pressure.
  void applyPressure(Point2D point);

  // Change cells into other cells depending on the heat.
  void applyHeat(Point2D point);

  // Calculate how long it takes for the next step to happen.
  double waitTime();
};

#endif // TETRIS_MACHINE_H
