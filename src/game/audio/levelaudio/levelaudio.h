#ifndef LEVEL_AUDIO_H
#define LEVEL_AUDIO_H

#include "levelaudio.ih"

/**
 * Plays audio related to the level model.
 */
class LevelAudio : public GameAudio
{
public:
  /**
   * Construct audio player for the level model.
   */
  LevelAudio(AudioFactory &audioFactory, LevelModel &levelModel);

  /**
   * Update the state of the audio player.
   */
  void update(double deltaTime) override;

private:
  shared_ptr<Sound> d_paperSound;

  LevelModel *d_levelModel;

  // Should a paper sound be played.
  bool d_playedPaper = false;
};

#endif // LEVEL_AUDIO_H