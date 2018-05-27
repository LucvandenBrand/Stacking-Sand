#ifndef PAUSEBLE_H
#define PAUSEBLE_H

#include "pauseble.h"

/**
 * An object that can be paused.
 */
class Pauseble
{
public:
  /**
   * (Un-)pauses the object.
   */
  void paused(bool pause);

  /**
   * Return the paused state.
   */
  bool paused();

private:
  bool d_paused = false;
};

#endif // PAUSEBLE_H