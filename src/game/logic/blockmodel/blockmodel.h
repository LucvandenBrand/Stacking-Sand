#ifndef BLOCK_MODEL_H
#define BLOCK_MODEL_H

#include "blockmodel.ih"

class BlockModel : public Model, public Pauseble
{
public:
  explicit BlockModel(TetrisModel &tetrisModel);

  // Set the moving direction.
  void move(Point2D shift);

  // Rotate the grid.
  void rotate();

  // Return the current position.
  Point2D position();

  // Return the current or next block in use.
  Grid currentBlock();
  Grid nextBlock();

  // Is the game in a failed state.
  bool gameOver();

  // Update the state.
  void step(double deltaTime) override;

  // Choose stamp and position.
  void reset();

  // The grid used.
  Grid grid();

private:
  TetrisModel *d_tetrisModel;

  /* Which blocks to use. */
  vector<Grid> d_blocks;
  Grid d_currentBlock, d_nextBlock;
  default_random_engine d_randomGenerator;

  /* Movement vars. */
  Point2D d_position, d_move;

  /* If the game is in a failed state. */
  bool d_gameOver = false;

  // Should the block be reset.
  bool d_shouldReset = false;

  // Check if this block overlaps with the tetrisGrid at position.
  bool overlap(Point2D newPosition);
};

#endif // BLOCK_MODEL_H
