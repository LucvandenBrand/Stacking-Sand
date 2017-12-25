#include "gridmachine.ih"

ostream& operator<<(ostream& out, const GridMachine& gridMachine)
{
    for (unsigned short posY = 0; posY < gridMachine.d_height; ++posY)
    {
      for (unsigned short posX = 0; posX < gridMachine.d_width; ++posX)
      {
        out << gridMachine.d_cells[gridMachine.project2D(posX, posY,
               gridMachine.d_width)] << ' ';
      }
      out << endl;
    }
    return out;
}
