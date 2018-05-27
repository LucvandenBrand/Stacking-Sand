#ifndef KILL_INPUT_PARSER_H
#define KILL_INPUT_PARSER_H

#include "killinputparser.ih"

/**
 * Input parser related to killing a model.
 */
class KillInputParser : public InputParser
{
public:
  /**
   * Construct the parser.
   */
  explicit KillInputParser(Model &model);

  /**
   * Parse input related killing a model.
   */
  void parse(InputState inputState) override;

private:
  Model *d_model;
};

#endif // KILL_INPUT_PARSER_H
