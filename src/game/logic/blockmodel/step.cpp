#include "blockmodel.ih"

void BlockModel::step(float deltaTime)
{
  if (this->d_tetrisModel->timeToWait() > 0) // We still have time left.
    return;

  if (this->d_shouldReset)
  {
    this->reset();
    this->d_shouldReset = false;
  }

  // Apply the move, and reset the move direction.
  Point2D newPosition = this->d_position;
  newPosition += this->d_move;
  this->d_move = Point2D(0, 0);

  // Prevent potential overlap.
  if (!overlap(newPosition))
    this->d_position = newPosition;

  // Check if the ground had been reached.
  if (overlap(this->d_position + Point2D(0, 1)))
  {
    // Stamp this block on the grid, and reset.
    this->stamp();
    this->d_shouldReset = true;
    return;
  }
  else   // Apply default gravity.
    this->d_position += Point2D(0, 1);
}
