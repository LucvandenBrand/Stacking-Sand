#ifndef BLOCK_MODEL_H
#define BLOCK_MODEL_H

#include "blockmodel.ih"

class BlockModel : public Model, public Pauseble
{
public:
  BlockModel(TetrisModel *tetrisModel);

  // Set the moving direction.
  void move(Point2D shift);

  // Return the current position.
  Point2D position();

  // Return the current or next block in use.
  Grid currentBlock();
  Grid nextBlock();

  Grid *grid();

  // Update the state.
  void step(float deltaTime);

private:
  TetrisModel *d_tetrisModel;
  Grid *d_tetrisGrid;
  vector<Grid> d_blocks;
  unsigned short d_currentBlockIndex, d_nextBlockIndex;
  Point2D d_position, d_move;

  // Should the block be reset.
  bool d_shouldReset = false;

  // Copy source onto destination at d_position.
  void stamp();

  // Check if this block overlaps with the tetrisGrid at position.
  bool overlap(Point2D newPosition);

  // Choose stamp and position.
  void reset();
};

#endif // BLOCK_MODEL_H
