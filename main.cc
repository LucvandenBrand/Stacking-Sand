#include "main.ih"

int main(int argc, char **argv)
{
  // Initialise our game.
  Tetris tetris;
  Painter painter(&tetris);
  Controller controller(&tetris);

  if (!painter.init())
  {
    cout << "ERROR initializing painter!" << endl;
    cout << SDL_GetError();
    return -1;
  }

  // Loop grid for a few iterations.
  bool keepRunning = true;
  while(keepRunning)
  {
    painter.paint();
    keepRunning = controller.processEvents();
    tetris.step();
  }

  return 0;
}
