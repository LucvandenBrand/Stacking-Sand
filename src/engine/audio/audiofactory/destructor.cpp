#include "audiofactory.ih"

AudioFactory::~AudioFactory()
{
  d_soundCache.clear();
  d_musicCache.clear();
}
