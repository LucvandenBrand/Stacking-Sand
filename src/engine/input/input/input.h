#ifndef INPUT_H
#define INPUT_H

#include "input.ih"

/**
 * Reader of keyboard events.
 */
class Input
{
public:
  /**
   * Return the current state of the input.
   */
  static InputState getState();
};

#endif // INPUT_H
