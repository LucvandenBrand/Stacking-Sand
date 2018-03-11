#include "tetrisaudio.ih"

void TetrisAudio::update(double deltaTime)
{
  unsigned int scoreDifference = d_tetrisModel->score() - d_lastScore;
  d_lastScore = d_tetrisModel->score();

  // If there has been scored, play a scoring sound.
  if (scoreDifference > 0)
    d_scoreSounds[scoreSoundIndex(scoreDifference)]->play();
}