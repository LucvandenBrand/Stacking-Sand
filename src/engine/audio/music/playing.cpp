#include "music.ih"

bool Music::playing()
{
  return Mix_PlayingMusic() != 0;
}