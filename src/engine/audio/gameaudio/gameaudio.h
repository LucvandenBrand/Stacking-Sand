#ifndef GAME_AUDIO_H
#define GAME_AUDIO_H

#include "gameaudio.ih"

/**
 * Plays the appropriate sound / music for a game model.
 */
class GameAudio
{
public:
  /**
   * Abstract method for updating the state of the player.
   */
  virtual void update(double deltaTime) = 0;
};

#endif // GAME_AUDIO_H