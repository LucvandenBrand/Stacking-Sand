#include "music.ih"

bool Music::paused()
{
  return Mix_PausedMusic() != 0;
}