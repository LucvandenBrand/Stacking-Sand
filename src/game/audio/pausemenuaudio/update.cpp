#include "pausemenuaudio.ih"

void PauseMenuAudio::update(double deltaTime)
{
  // Play the music appropriate for the title or the game.
  if (!Music::playing())
    d_currentMusic->play(-1);

  bool isFirstStart = d_pauseMenuModel->firstStart();
  if (!isFirstStart) // The title screen has closed.
  {
    if (d_wasFirstStart) // The title screen was open the previous frame.
    {
      Music::halt();
      d_pauseSound->play();
      d_currentMusic = d_gameMusic.get();
    }

    // Manage pause sound effects.
    bool isPaused = d_pauseMenuModel->paused();
    if (isPaused)
      Music::pause();
    else if (Music::paused())
      Music::resume();
    if (isPaused && !d_wasPaused)
      d_pauseSound->play();

    d_wasPaused = isPaused;
  }

  d_wasFirstStart = isFirstStart;
}