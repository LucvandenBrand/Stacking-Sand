#include "levelaudio.ih"

void LevelAudio::update(double deltaTime)
{
  double level = d_levelModel->level();

  double difference, index;
  difference = modf(level , &index);

  // Play a paper moving sound.
  if (difference != 0 && !d_playedPaper)
  {
    d_paperSound.get()->play();
    d_playedPaper = true;
  }
  else if (difference == 0)
    d_playedPaper = false;

  // Play the main music appropriate for the level.
  if (!Music::playing())
    d_gameMusic.get()->play(-1);
}