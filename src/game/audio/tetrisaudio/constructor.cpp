#include "tetrisaudio.ih"

TetrisAudio::TetrisAudio(AudioFactory &audioFactory, TetrisModel &tetrisModel)
  : d_tetrisModel(&tetrisModel)
{
  d_lastScore = tetrisModel.score();

  try
  {
    d_scoreSounds.reserve(1);
    d_scoreSounds.push_back(audioFactory.sound("data/coin.wav"));
    d_scoreSounds.push_back(audioFactory.sound("data/coins.wav"));
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not load sound:" << invalidArgument.what() << endl;
  }
}