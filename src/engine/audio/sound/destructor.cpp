#include "sound.ih"

Sound::~Sound()
{
  Mix_FreeChunk(d_chunk);
}