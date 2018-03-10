#include "sound.ih"

void Sound::play()
{
  Mix_PlayChannel(-1, d_chunk, 0);
}