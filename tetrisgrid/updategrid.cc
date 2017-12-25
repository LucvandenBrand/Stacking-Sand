#include "tetrisgrid.ih"

void TetrisGrid::updateGrid()
{
  for (short posY = height()-1; posY > -1; --posY)
  {
    // Move cells down and count the amount of cells in one row.
    unsigned short cellCount = 0;
    for (unsigned short posX = 0; posX < width(); ++posX)
    {
      if (belowEmpty(posX, posY))
        swapCells(posX, posY, posX, posY+1);
      else if (cell(posX, posY) > 0)
        ++cellCount;
    }

    // If the entire row is stationary cells, decrease their value.
    if (cellCount == width())
      for (unsigned short posX = 0; posX < width(); ++posX)
        --*(cellReference(posX, posY));
  }
}
