#ifndef LEVEL_MODEL_H
#define LEVEL_MODEL_H

#include "levelmodel.ih"

/**
 * Changes the level integer into a float value for use in the story.
 */
class LevelModel : public Model, public Pauseble
{
public:
  /**
   * Create a model of the level.
   */
  explicit LevelModel(TetrisModel &tetrisModel);

  /**
   * Every step, sync the level with tetrisModel.
   */
  void step(double deltaTime) override;

  /**
   * Returns the current transition level.
   */
  double level();

private:
  double d_level = 0;

  // The speed at which transitions are scaled.
  const double TRANSITION_SCALE = 0.65;
  TetrisModel *d_tetrisModel;
};

#endif // LEVEL_MODEL_H