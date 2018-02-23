#ifndef PAUSE_MENU_MODEL_H
#define PAUSE_MENU_MODEL_H

#include "pausemenumodel.ih"

class PauseMenuModel : public Model
{
public:
  /* Initialize with all pausebles that need to be paused when toggled. */
  explicit PauseMenuModel(initializer_list<Pauseble*> pausebles);

  void step(float deltaTime) override ;

  /* Is the game paused or not. */
  bool paused();

  /* Toggles the paused state on or off. */
  void toggle();

private:
  bool d_paused = false;
  vector<Pauseble*> d_pausebles;
};

#endif /* PAUSE_MENU_MODEL_H */