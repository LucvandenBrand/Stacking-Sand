#ifndef KILL_INPUT_PARSER_H
#define KILL_INPUT_PARSER_H

#include "killinputparser.ih"

class KillInputParser : public InputParser
{
public:
  explicit KillInputParser(Model &model);
  void parse(InputState inputState) override;

private:
  Model *d_model;
};

#endif /* KILL_INPUT_PARSER_H */
