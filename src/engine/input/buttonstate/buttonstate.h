#ifndef BUTTON_STATE_H
#define BUTTON_STATE_H

typedef const unsigned short Button;
typedef unsigned short ButtonState;
typedef struct
{
  ButtonState upButtons = 0;
  ButtonState downButtons = 0;
} InputState;

Button LEFT   = (1u << 0);
Button RIGHT  = (1u << 1);
Button UP     = (1u << 2);
Button DOWN   = (1u << 3);
Button START  = (1u << 4);
Button ESCAPE = (1u << 5);

#endif /* BUTTON_STATE_H */
