#include "blockmodel.ih"

void BlockModel::step(double deltaTime)
{
  if (paused()) // If the object is paused, do nothing.
    return;

  if (d_tetrisModel->timeToWait() > 0 && !d_speedup) // We still have time left.
    return;

  d_speedup = false;

  if (d_shouldReset)
  {
    reset();
    d_shouldReset = false;
  }

  if (d_gameOver) // Game over, do nothing.
    return;

  if (d_rotate) // Rotate the current block, if possible.
  {
    Grid rotatedGrid = rotateGrid(currentBlock());
    if (!overlap(d_position, rotatedGrid))
      d_currentBlock = rotatedGrid;
    d_rotate = false;
  }

  // Apply the move, and reset the move direction.
  Point2D newPosition = d_position + d_move;
  d_move = Point2D(0, 0);

  // Prevent potential overlap.
  if (!overlap(newPosition))
    d_position = newPosition;

  // Check if the ground had been reached.
  if (overlap(d_position + Point2D(0, 1)))
  {
    // Stamp this block on the grid, and reset.
    d_tetrisModel->stamp(currentBlock(), d_position);
    d_shouldReset = true;
    return;
  }
  else   // Apply default gravity.
    d_position += Point2D(0, 1);
}
