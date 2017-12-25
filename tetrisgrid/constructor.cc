#include "tetrisgrid.ih"

TetrisGrid::TetrisGrid(unsigned short width, unsigned short height) :
                         GridMachine(width, height)
{
  this->d_score = 0;
}
