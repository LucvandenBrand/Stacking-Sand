#ifndef GRIDMACHINE_H
#define GRIDMACHINE_H

#include "gridmachine.ih"

class GridMachine
{
private:
  unsigned short d_width, d_height;
  vector<unsigned short> d_cells;

  // Project a 2D point to a 1D point.
  unsigned short project2D(unsigned short posX, unsigned short posY,
                           unsigned short width) const;
protected:
  // Abstract logic used to update the grid to the next state.
  virtual void updateGrid() = 0;

  // Return a reference to a particular cell.
  unsigned short* cellReference(unsigned short posX, unsigned short posY);

public:
  GridMachine(unsigned short width, unsigned short height);

  // Insert and retrieve cell values.
  void cell(unsigned short posX, unsigned short posY, unsigned short value);
  unsigned short cell(unsigned short posX, unsigned short posY);

  // Return the width and height of the grid.
  unsigned short width();
  unsigned short height();

  // Step to the next state of the grid.
  void step();

  // Overloading the insertion operator for the grid.
  friend ostream& operator<<(ostream& out, const GridMachine& gridMachine);
};

#endif // GRIDMACHINE_H
