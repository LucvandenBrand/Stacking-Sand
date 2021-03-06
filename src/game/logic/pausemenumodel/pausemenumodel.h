#ifndef PAUSE_MENU_MODEL_H
#define PAUSE_MENU_MODEL_H

#include "pausemenumodel.ih"

/**
 * Pauses the entire game and remembers if the game just started.
 */
class PauseMenuModel : public Model
{
public:
  /**
   * Initialize with all pausebles that need to be paused when toggled.
   */
  explicit PauseMenuModel(initializer_list<Pauseble*> pausebles, GameOverModel &gameOverModel);

  void step(double deltaTime) override;

  /**
   * Is the game paused or not.
   */
  bool paused();

  /**
   * Is this the first time the game has been started or not.
   */
  bool firstStart();

  /**
   * Is the game in a failed state or not.
   */
  bool gameOver();

  /**
   * Toggles the paused state on or off.
   */
  void toggle();

private:
  bool d_paused = true;
  bool d_firstStart = true;
  vector<Pauseble*> d_pausebles;
  GameOverModel &d_gameOverModel;
};

#endif // PAUSE_MENU_MODEL_H