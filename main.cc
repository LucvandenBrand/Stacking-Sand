#include "main.ih"

int main(int argc, char **argv)
{
  // Initialise our game.
  Tetris tetris;

  // Loop grid for a few iterations.
  for (unsigned short i = 0; i < 10; ++i)
  {
    cout << "Step #" << i << " - " << "Score = " << tetris.tetrisMachine().score() << ':'
         << endl << tetris.grid();
    tetris.step();
  }

  return 0;
}
