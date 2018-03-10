#ifndef MUSIC_H
#define MUSIC_H

#include "music.ih"

class Music
{
public:
  explicit Music(Mix_Music *music);
  ~Music();

  /* Make this music play for loops. */
  void play(int loops);

  /* Return true if music is playing. */
  static bool playing();

  /* Pause the current music. */
  static void pause();

  /* Return true if music is paused. */
  static bool paused();

  /* Stop the curpausedrent music. */
  static void halt();

  /* Resume the current music. */
  static void resume();
private:
  Mix_Music *d_music;
};

#endif /* MUSIC_H */