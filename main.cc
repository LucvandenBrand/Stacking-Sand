#include "main.ih"

int main(int argc, char **argv)
{
  // Initialise our playing field.
  TetrisGrid tetrisGrid(3, 5);

  // Insert cell for testing.
  tetrisGrid.cell(0, 0, 4);
  tetrisGrid.cell(1, 0, 4);
  tetrisGrid.cell(2, 0, 4);

  tetrisGrid.cell(0, 1, 4);
  tetrisGrid.cell(1, 1, 4);
  tetrisGrid.cell(2, 1, 4);

  // Loop grid for a few iterations.
  for (unsigned short i = 0; i < 10; ++i)
  {
    cout << "Step #" << i << ':' << endl << tetrisGrid;
    tetrisGrid.step();
  }

  return 0;
}
