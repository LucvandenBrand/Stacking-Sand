#include "gridmachine.ih"

void GridMachine::cell(unsigned short posX, unsigned short posY,
                       unsigned short value)
{
  *(this->cellReference(posX, posY)) = value;
}
