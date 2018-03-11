#ifndef GAME_AUDIO_H
#define GAME_AUDIO_H

#include "gameaudio.ih"

class GameAudio
{
public:
  virtual void update(double deltaTime) = 0;
};

#endif /* GAME_AUDIO_H */