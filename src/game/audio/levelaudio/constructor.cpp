#include "levelaudio.ih"

LevelAudio::LevelAudio(AudioFactory &audioFactory, LevelModel &levelModel)
  : d_levelModel(&levelModel)
{
  try
  {
    d_gameMusic = audioFactory.music("data/gameMusic.wav");
    d_paperSound = audioFactory.sound("data/paper.wav");
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not load music or sound:" << invalidArgument.what() << endl;
  }
}