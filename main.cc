#include "main.ih"

int main(int argc, char **argv)
{
  // Initialise our game.
  Tetris tetris;
  Painter painter(&tetris);

  if (!painter.init())
  {
    cout << "ERROR initializing painter!" << endl;
    return -1;
  }

  // Loop grid for a few iterations.
  for (unsigned short i = 0; i < 30; ++i)
  {
    painter.paint();
    tetris.step();

    // Wait 1/4th of a second.
    SDL_Delay(250);
  }

  return 0;
}
