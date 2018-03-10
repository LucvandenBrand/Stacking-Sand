#include "audiofactory.ih"

shared_ptr<Sound> AudioFactory::sound(string soundPath)
{
  if (d_soundCache.count(soundPath) == 0)
  { // Sound is new, try to load it.
    Mix_Chunk* chunk = nullptr;
    chunk = Mix_LoadWAV(soundPath.c_str());
    if (!chunk)
      throw invalid_argument(Mix_GetError());

    /* Creating the sound was successful: store it. */
    d_soundCache.emplace(soundPath, make_shared<Sound>(chunk));
  }

  return d_soundCache.at(soundPath);
}