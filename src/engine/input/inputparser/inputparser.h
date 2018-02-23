#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "inputparser.ih"

class InputParser
{
public:
  virtual void parse(InputState inputState) = 0;
};

#endif /* INPUT_PARSER_H */
