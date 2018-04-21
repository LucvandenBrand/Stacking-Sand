#include "pausemenuaudio.ih"

PauseMenuAudio::PauseMenuAudio(AudioFactory &audioFactory, PauseMenuModel &pauseMenuModel)
: d_pauseMenuModel(&pauseMenuModel)
{
  try
  {
    d_titleMusic = audioFactory.music("data/titleMusic.wav");
    d_currentMusic = d_titleMusic.get();
    d_gameMusic = audioFactory.music("data/gameMusic.wav");
    d_pauseSound = audioFactory.sound("data/pause.wav");
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not load music or sound:" << invalidArgument.what() << endl;
  }
}