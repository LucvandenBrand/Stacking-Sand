#include "grid.ih"

ostream& operator<<(ostream& out, const Grid& grid)
{
    for (unsigned short posY = 0; posY < grid.d_height; ++posY)
    {
      for (unsigned short posX = 0; posX < grid.d_width; ++posX)
      {
        out << grid.d_cells[grid.project2D(Point2D(posX, posY),
               grid.d_width)] << ' ';
      }
      out << endl;
    }
    return out;
}
