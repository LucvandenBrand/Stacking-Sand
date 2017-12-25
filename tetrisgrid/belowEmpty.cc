#include "tetrisgrid.ih"

bool TetrisGrid::belowEmpty(unsigned short posX, unsigned short posY)
{
  posY += 1;
  return (posY < height()) && (cell(posX, posY) == 0);
}
