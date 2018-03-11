#ifndef LEVEL_MODEL_H
#define LEVEL_MODEL_H

#include "levelmodel.ih"

class LevelModel : public Model
{
public:
  explicit LevelModel(TetrisModel &tetrisModel);

  /* Every step, try to sync with tetrisModel. */
  void step(double deltaTime) override;

  /* Returns the current transition level. */
  double level();

private:
  double d_level = 0;

  /* The speed at which transitions are scaled. */
  const double TRANSITION_SCALE = 0.7;
  TetrisModel *d_tetrisModel;
};

#endif /* LEVEL_MODEL_H */