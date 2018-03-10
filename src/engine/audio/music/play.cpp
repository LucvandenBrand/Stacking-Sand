#include "music.ih"

void Music::play(int loops)
{
  Mix_PlayMusic(d_music, loops);
}