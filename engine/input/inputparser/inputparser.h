#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include "inputparser.ih"

class InputParser
{
public:
  virtual void parse(ButtonState buttonState) = 0;
};

#endif /* INPUTPARSER_H */
