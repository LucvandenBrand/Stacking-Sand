#ifndef TETRISGRID_H
#define TETRISGRID_H

#include "tetrisgrid.ih"

class TetrisGrid : public GridMachine
{
private:
  // Score of the game.
  unsigned short d_score;

  /* Return whether there is a zero value at (posX, posY+1).
   * If posY > height, we return false. */
  bool belowEmpty(unsigned short posX, unsigned short posY);

  // Swap the value of two cells.
  void swapCells(unsigned short posX1, unsigned short posY1,
                 unsigned short posX2, unsigned short posY2);

protected:
  // Implementing the gridmachine update method to simulate tetris rules.
  void updateGrid();

public:
  TetrisGrid(unsigned short width, unsigned short height);

  // Return the current Score.
  unsigned short score();
};

#endif // TETRISGRID_H
