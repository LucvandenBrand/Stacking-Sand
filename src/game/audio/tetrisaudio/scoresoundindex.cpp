#include "tetrisaudio.ih"

unsigned int TetrisAudio::scoreSoundIndex(unsigned int scoreDifference)
{
  unsigned int index = 0;
  if (scoreDifference > SCORE_COINS)
    index++;

  return min(index, (unsigned int) d_scoreSounds.size());
}