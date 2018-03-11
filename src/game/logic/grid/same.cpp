#include "grid.ih"

bool Grid::same(Grid other)
{
  if (d_cells.size() != other.d_cells.size())
    return false;

  return equal(d_cells.begin(), d_cells.end(), other.d_cells.begin());
}