#include "gridmachine.ih"

unsigned short GridMachine::project2D(unsigned short posX, unsigned short posY,
                                      unsigned short width) const
{
  return posY*width + posX;
}
