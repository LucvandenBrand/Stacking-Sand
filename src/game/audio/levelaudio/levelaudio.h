#ifndef LEVEL_AUDIO_H
#define LEVEL_AUDIO_H

#include "levelaudio.ih"

class LevelAudio : public GameAudio
{
public:
  explicit LevelAudio(AudioFactory &audioFactory, LevelModel &levelModel);
  void update(double deltaTime) override;

private:
  shared_ptr<Music> d_gameMusic;
  shared_ptr<Sound> d_paperSound;

  LevelModel *d_levelModel;

  /* Should a paper sound be played. */
  bool d_playedPaper = false;
};

#endif /* LEVEL_AUDIO_H */