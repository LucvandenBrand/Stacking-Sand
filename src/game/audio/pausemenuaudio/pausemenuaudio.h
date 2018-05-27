#ifndef PAUSE_MENU_AUDIO_H
#define PAUSE_MENU_AUDIO_H

#include "pausemenuaudio.ih"

/**
 * Audio player for the pause menu model.
 */
class PauseMenuAudio : public GameAudio {
public:
  /**
   * Construct audio player for the pause menu model.
   */
  explicit PauseMenuAudio(AudioFactory &audioFactory, PauseMenuModel &pauseMenuModel);

  /**
   * Update the audio player state.
   */
  void update(double deltaTime) override;

private:
  shared_ptr<Music> d_titleMusic, d_gameMusic;
  Music* d_currentMusic;
  shared_ptr<Sound> d_pauseSound, d_startSound;

  PauseMenuModel* d_pauseMenuModel;

  // Remember changes for the pause menu and the title-screen.
  bool d_wasPaused = false, d_wasFirstStart = false;
};

#endif // PAUSE_MENU_AUDIO_H