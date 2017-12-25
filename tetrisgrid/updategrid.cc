#include "tetrisgrid.ih"

void TetrisGrid::updateGrid()
{
  for (short posY = height()-1; posY > -1; --posY)
    for (unsigned short posX = 0; posX < width(); ++posX)
    {
      if (belowEmpty(posX, posY))
      {
        unsigned short value = cell(posX, posY);
        cell(posX, posY, 0);
        cell(posX, posY + 1, value);
      }
    }
}
