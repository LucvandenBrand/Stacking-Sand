#ifndef PAUSE_MENU_AUDIO_H
#define PAUSE_MENU_AUDIO_H

#include "pausemenuaudio.ih"

class PauseMenuAudio : public GameAudio {
public:
  explicit PauseMenuAudio(AudioFactory &audioFactory, PauseMenuModel &pauseMenuModel);
  void update(double deltaTime) override;

private:
  shared_ptr<Music> d_titleMusic, d_gameMusic;
  Music* d_currentMusic;
  shared_ptr<Sound> d_pauseSound;

  PauseMenuModel* d_pauseMenuModel;

  /* Remember changes for the pause menu and the titlescreen. */
  bool d_wasPaused = false, d_wasFirstStart = false;
};

#endif /* PAUSE_MENU_AUDIO_H */