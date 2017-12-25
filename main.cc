#include "main.ih"

int main(int argc, char **argv)
{
  // Initialise our playing field.
  TetrisGrid tetrisGrid(10, 10);

  // Insert cell for testing.
  tetrisGrid.cell(0, 0, 3);
  tetrisGrid.cell(0, 1, 4);
  tetrisGrid.cell(0, 2, 1);

  // Loop grid for a few iterations.
  for (unsigned short i = 0; i < 10; ++i)
  {
    cout << "Step #" << i << ':' << endl << tetrisGrid;
    tetrisGrid.step();
  }

  return 0;
}
