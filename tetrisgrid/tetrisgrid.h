#ifndef TETRISGRID_H
#define TETRISGRID_H

#include "tetrisgrid.ih"

class TetrisGrid : public GridMachine
{
private:
  /* Return whether there is a zero value at (posX, posY+1).
   * If posY > height, we return false. */
  bool belowEmpty(unsigned short posX, unsigned short posY);

protected:
  // Implementing the gridmachine update method.
  void updateGrid();

public:
  TetrisGrid(unsigned short width, unsigned short height);
};

#endif // TETRISGRID_H
