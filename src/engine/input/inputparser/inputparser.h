#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "inputparser.ih"

/**
 * Parser for an input state.
 */
class InputParser
{
public:
  /**
   * Abstract method for parsing the state.
   */
  virtual void parse(InputState inputState) = 0;
};

#endif // INPUT_PARSER_H
