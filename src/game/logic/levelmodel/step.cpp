#include "levelmodel.ih"

void LevelModel::step(float deltaTime)
{
  int level = d_tetrisModel->level();
  if (level != d_level)
  { // The level has changed, restart the animation.
    d_level += TRANSITION_SCALE * deltaTime;
    if (d_level > level)
      d_level = level;
  }
}