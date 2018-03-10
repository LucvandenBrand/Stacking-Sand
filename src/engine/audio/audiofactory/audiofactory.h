#ifndef AUDIO_FACTORY_H
#define AUDIO_FACTORY_H

#include "audiofactory.ih"

class AudioFactory
{
public:
  ~AudioFactory();

  shared_ptr<Sound> sound(string soundPath);
  shared_ptr<Music> music(string musicPath);

private:
  /* Hash-maps of all and and music loaded. */
  map<string, shared_ptr<Sound>> d_soundCache;
  map<string, shared_ptr<Music>> d_musicCache;
};

#endif /* AUDIO_FACTORY_H */