#include "main.ih"

int main(int argc, char **argv)
{
  // Initialise our playing field.
  Grid grid(3, 5);
  *(grid.cell(Point2D(0,0))) = 4;

  TetrisMachine tetrisMachine(&grid);
  TetrisBlock tetrisBlock(&grid);

  // Loop grid for a few iterations.
  for (unsigned short i = 0; i < 10; ++i)
  {
    cout << "Step #" << i << " - " << "Score = " << tetrisMachine.score() << ':'
         << endl << grid;
    tetrisMachine.step();
  }

  return 0;
}
