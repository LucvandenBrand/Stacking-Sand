#ifndef PAINTER_H
#define PAINTER_H

#include "painter.ih"

class Painter
{
private:
  Tetris* d_tetris;
public:
  Painter(Tetris* tetris);
  void paint();
};

#endif // PAINTER_H
