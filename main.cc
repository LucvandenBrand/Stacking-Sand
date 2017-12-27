#include "main.ih"

int main(int argc, char **argv)
{
  // Initialise our game.
  Tetris tetris;
  Painter painter(&tetris);

  // Loop grid for a few iterations.
  for (unsigned short i = 0; i < 10; ++i)
  {
    painter.paint();
    tetris.step();
  }

  return 0;
}
