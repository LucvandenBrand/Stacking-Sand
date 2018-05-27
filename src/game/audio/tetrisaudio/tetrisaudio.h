#ifndef TETRIS_AUDIO_H
#define TETRIS_AUDIO_H

#include "tetrisaudio.ih"

/**
 * Plays audio for the tetris model.
 */
class TetrisAudio: public GameAudio
{
public:
  /**
   * Construct the audio player for the tetris model.
   */
  TetrisAudio(AudioFactory &audioFactory, TetrisModel &tetrisModel);

  /**
   * Update the state of the audio player.
   */
  void update(double deltaTime) override;

private:
  // Audio effect constants.
  const unsigned int SCORE_COINS = 15;

  // Return the sound effect index to use based on the score difference.
  unsigned int scoreSoundIndex(unsigned int scoreDifference);

  TetrisModel *d_tetrisModel;
  unsigned int d_lastScore;
  vector<shared_ptr<Sound>> d_scoreSounds;
};

#endif // TETRIS_AUDIO_H