#include "painter.ih"

void Painter::paint()
{
  cout << "Score = " << this->d_tetris->tetrisMachine().score() << ':'
       << endl << this->d_tetris->grid();
}
