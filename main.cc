#include "main.ih"

int main(int argc, char **argv)
{
  // Initialise our playing field.
  TetrisGrid tetrisGrid(3, 5);

  // Insert cell for testing.
  tetrisGrid.cell(Point2D(0, 0), 4);

  // Loop grid for a few iterations.
  for (unsigned short i = 0; i < 10; ++i)
  {
    cout << "Step #" << i << " - " << "Score = " << tetrisGrid.score() << ':'
         << endl << tetrisGrid;
    tetrisGrid.step();
  }

  return 0;
}
