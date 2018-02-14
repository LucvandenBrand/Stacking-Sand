#ifndef GRID_H
#define GRID_H

#include "grid.ih"

class Grid
{
private:
  unsigned short d_width, d_height;
  vector<unsigned short> d_cells;

  // Project a 2D point to a 1D point.
  unsigned short project2D(Point2D point, unsigned short width) const;
public:
  Grid(unsigned short width, unsigned short height);

  // Return a cell.
  unsigned short* cell(Point2D point);

  // Return the width and height of the grid.
  unsigned short width();
  unsigned short height();

  // Overloading the insertion operator for the grid.
  friend ostream& operator<<(ostream& out, const Grid& grid);
};

#endif // GRID_H
