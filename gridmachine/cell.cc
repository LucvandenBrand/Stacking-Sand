#include "gridmachine.ih"

unsigned short GridMachine::cell(unsigned short posX, unsigned short posY)
{
  return *(this->cellReference(posX, posY));
}
