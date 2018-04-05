#include "tetrismodel.ih"

unsigned int TetrisModel::level()
{
  unsigned currentLevel = 0;
  for (unsigned level = 0; level < NUM_LEVELS; level++)
    if (d_score >= SCORE_LEVEL[level])
      currentLevel = level;
  return currentLevel;
}
