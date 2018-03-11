#ifndef TETRIS_AUDIO_H
#define TETRIS_AUDIO_H

#include "tetrisaudio.ih"

class TetrisAudio: public GameAudio
{
public:
  TetrisAudio(AudioFactory &audioFactory, TetrisModel &tetrisModel);

  void update(double deltaTime) override;

private:
  /* Audio effect constants. */
  const unsigned int SCORE_COINS = 15;

  /* Return the sound effect index to use based on the score difference. */
  unsigned int scoreSoundIndex(unsigned int scoreDifference);

  TetrisModel *d_tetrisModel;
  unsigned int d_lastScore;
  vector<shared_ptr<Sound>> d_scoreSounds;
};

#endif /* TETRIS_AUDIO_H */