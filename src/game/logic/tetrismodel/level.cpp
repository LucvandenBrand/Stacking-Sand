#include "tetrismodel.ih"

unsigned int TetrisModel::level()
{
  unsigned int currentLevel;
  if (d_score >= SCORE_LEVEL6)
    currentLevel = 6;
  else if (d_score >= SCORE_LEVEL5)
    currentLevel = 5;
  else if (d_score >= SCORE_LEVEL4)
    currentLevel = 4;
  else if (d_score >= SCORE_LEVEL3)
    currentLevel = 3;
  else if (d_score >= SCORE_LEVEL2)
    currentLevel = 2;
  else if (d_score >= SCORE_LEVEL1)
    currentLevel = 1;
  else
    currentLevel = 0;

  return currentLevel;
}
