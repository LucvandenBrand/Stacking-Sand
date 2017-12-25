#include "tetrisgrid.ih"

void TetrisGrid::swapCells(unsigned short posX1, unsigned short posY1,
                           unsigned short posX2, unsigned short posY2)
{
  unsigned short cell1 = cell(posX1, posY1);
  unsigned short cell2 = cell(posX2, posY2);
  cell(posX1, posY1, cell2);
  cell(posX2, posY2, cell1);
}
