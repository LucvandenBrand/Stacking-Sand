#ifndef BUTTONSTATE_H
#define BUTTONSTATE_H

typedef enum
{
  LEFT  = (1u << 0),
  RIGHT = (1u << 1),
  UP    = (1u << 2),
  DOWN  = (1u << 3),
  START = (1u << 4)
} Buttons;

typedef unsigned int ButtonState;

#endif /* BUTTONSTATE_H */
