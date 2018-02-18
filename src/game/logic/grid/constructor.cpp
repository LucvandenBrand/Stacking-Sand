#include "grid.ih"

Grid::Grid(unsigned short width, unsigned short height) :
                  d_width(width), d_height(height)
{
  // Initialise the vector with zeroes.
  unsigned short length = width * height;
  this->d_cells.reserve(length);
  for (unsigned short i = 0; i < length; ++i)
    this->d_cells.push_back(0);
}
