#ifndef PAUSEBLE_H
#define PAUSEBLE_H

#include "pauseble.h"

class Pauseble
{
public:
  void paused(bool pause);
  bool paused();
private:
  bool d_paused = false;
};

#endif /*PAUSEBLE_H */