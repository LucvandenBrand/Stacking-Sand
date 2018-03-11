#include "sound.ih"

void Sound::setVolume(float volume)
{
  volume = clamp(volume, 0.f, 1.f);
  auto mixVolume = (unsigned const short) (volume * MIX_MAX_VOLUME);
  Mix_VolumeChunk(d_chunk, mixVolume);
}