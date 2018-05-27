#ifndef SOUND_H
#define SOUND_H

#include "sound.ih"

/**
 * A piece of sound to be played.
 */
class Sound
{
public:
  /**
   * Construct a sound with an SDL Mix chunk.
   */
  explicit Sound(Mix_Chunk *chunk);

  /**
   * Free memory allocated for the sound.
   */
  ~Sound();

  /**
   * Play the sound effect.
   */
  void play();

  /**
   * Set the volume (between 0..1) for the sound.
   */
  void setVolume(float volume);

private:
  Mix_Chunk *d_chunk;
};

#endif // SOUND_H