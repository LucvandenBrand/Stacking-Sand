#ifndef GRID_H
#define GRID_H

#include "grid.ih"

/**
 * General model for integer values in a grid.
 */
class Grid
{
public:
  /**
   * Construct a grid of width x height.
   */
  Grid(unsigned short width, unsigned short height);

  /**
   * Return a cell.
   */
  unsigned short cell(Point2D point);

  /**
   * Set a cell to a value.
   */
  void cell(Point2D point, unsigned short value);

  /**
   * Swap the values of two cells.
   */
  void swapCells(Point2D fromCell, Point2D toCell);

  /**
   * Return the width of the grid.
   */
  unsigned short width();

  /**
   * Return the height of the grid.
   */
  unsigned short height();

  /**
   * Overloading the insertion operator for the grid.
   */
  friend ostream& operator<<(ostream& out, const Grid& grid);

  /**
   * Is the compared object identical.
   */
  bool same(Grid other);

private:
  unsigned short d_width, d_height;
  vector<unsigned short> d_cells;

  // Project a 2D point to a 1D point.
  unsigned short project2D(Point2D point, unsigned short width) const;
};

#endif // GRID_H
