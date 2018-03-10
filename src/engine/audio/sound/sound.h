#ifndef SOUND_H
#define SOUND_H

#include "sound.ih"

class Sound
{
public:
  explicit Sound(Mix_Chunk *chunk);
  ~Sound();

  /* Play the sound effect. */
  void play();

private:
  Mix_Chunk *d_chunk;
};

#endif /* SOUND_H */