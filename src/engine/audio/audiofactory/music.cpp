#include "audiofactory.ih"

shared_ptr<Music> AudioFactory::music(string musicPath)
{
  if (d_musicCache.count(musicPath) == 0)
  { // Music is new, try to load it.
    Mix_Music* music = nullptr;
    music = Mix_LoadMUS(musicPath.c_str());
    if (!music)
      throw invalid_argument(Mix_GetError());

    /* Creating the music was successful: store it. */
    d_musicCache.emplace(musicPath, make_shared<Music>(music));
  }

  return d_musicCache.at(musicPath);
}