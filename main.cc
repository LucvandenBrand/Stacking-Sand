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
  for (unsigned short i = 0; i < 10; ++i)
  {
    painter.paint();
    tetris.step();

    // Wait half a second.
    SDL_Delay(500);
  }

  return 0;
}
