#ifndef CONTROLLER_H
#define  CONTROLLER_H

#include "controller.ih"

class Controller
{
private:
  Tetris* d_tetris;

public:
  Controller(Tetris* tetris);

  // Poll all SDL events and handle them.
  bool processEvents();
};

#endif // CONTROLLER_H
