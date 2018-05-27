#ifndef AUDIO_FACTORY_H
#define AUDIO_FACTORY_H

#include "audiofactory.ih"

/**
 * Creates sound and music instances.
 */
class AudioFactory
{
public:
  /**
   * Free memory allocated by the factory.
   */
  ~AudioFactory();

  /**
   * Create a sound instance from the file at the given path.
   */
  shared_ptr<Sound> sound(string soundPath);

  /**
   * Create a music instance from the file at the given path.
   */
  shared_ptr<Music> music(string musicPath);

private:
  // Hash-maps of all and and music loaded.
  map<string, shared_ptr<Sound>> d_soundCache;
  map<string, shared_ptr<Music>> d_musicCache;
};

#endif // AUDIO_FACTORY_H