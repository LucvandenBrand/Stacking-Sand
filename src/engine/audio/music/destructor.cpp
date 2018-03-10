#include "music.ih"

Music::~Music()
{
  Mix_FreeMusic(d_music);
}