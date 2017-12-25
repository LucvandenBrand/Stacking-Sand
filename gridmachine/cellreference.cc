#include "gridmachine.ih"

unsigned short* GridMachine::cellReference(unsigned short posX,
                                           unsigned short posY)
{
  // Wrap around position indexes.
  posX %= this->d_width;
  posY %= this->d_height;

  return &(this->d_cells[project2D(posX, posY, this->d_width)]);
}
