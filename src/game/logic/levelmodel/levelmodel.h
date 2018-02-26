#ifndef LEVEL_MODEL_H
#define LEVEL_MODEL_H

#include "levelmodel.ih"

class LevelModel : public Model
{
public:
  explicit LevelModel(TetrisModel *tetrisModel);

  /* Every step, try to sync with tetrismodel. */
  void step(float deltaTime) override;

  /* Returns the current transition level. */
  float level();

private:
  float d_level = 0;

  /* The speed at which transitions are scaled. */
  const float TRANSITION_SCALE = 0.5;
  TetrisModel *d_tetrisModel;
};

#endif /* LEVEL_MODEL_H */