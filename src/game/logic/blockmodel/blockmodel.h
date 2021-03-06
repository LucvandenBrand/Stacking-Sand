#ifndef BLOCK_MODEL_H
#define BLOCK_MODEL_H

#include "blockmodel.ih"

/**
 * A block (containing multiple cells) to be moved and placed in the grid.
 */
class BlockModel : public Model, public Pauseble
{
public:
  /**
   * Construct a new block.
   */
  explicit BlockModel(TetrisModel &tetrisModel);

  /**
   * Set the moving direction.
   */
  void move(Point2D shift);

  /**
   * Set the block to rotate its current grid.
   */
  void rotate();

  /**
   * Set the block to move down faster.
   */
  void speedup();

  /**
   * Return the current position.
   */
  Point2D position();

  /**
   * Return the current block in use.
   */
  Grid currentBlock();

  /**
   * Return the next block to use.
   */
  Grid nextBlock();

  /**
   * Is the game in a failed state.
   */
  bool gameOver();

  /**
   * Return true if a block has been placed.
   */
  bool placed();

  /**
   * Update the state.
   */
  void step(double deltaTime) override;

  /**
   * Choose stamp and position.
   */
  void reset();

  /**
   * The grid used.
   */
  Grid grid();

private:
  TetrisModel *d_tetrisModel;

  // The currently chosen blocks.
  Grid d_currentBlock, d_nextBlock;

  // Random objects to determine which blocks/cells to use.
  vector<int> d_cellAvailability;
  default_random_engine d_randomGenerator;

  // Movement vars.
  Point2D d_position, d_move;
  bool d_rotate = false;

  // If the game is in a failed state.
  bool d_gameOver = false;

  // Should the block be reset.
  bool d_shouldReset = false;

  // Should the next step happen regardless of time.
  bool d_speedup = false;

  // Check if this block overlaps with the tetrisGrid at position.
  bool overlap(Point2D newPosition);
  bool overlap(Point2D newPosition, Grid newGrid);

  // Generate a new grid.
  Grid generateBlock();

  // Rotate the given grid.
  Grid rotateGrid(Grid grid);
};

#endif // BLOCK_MODEL_H
