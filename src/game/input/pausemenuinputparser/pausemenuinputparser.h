#ifndef PAUSE_MENU_INPUT_PARSER_H
#define PAUSE_MENU_INPUT_PARSER_H

#include "pausemenuinputparser.ih"

class PauseMenuInputParser : public InputParser
{
public:
  explicit PauseMenuInputParser(PauseMenuModel &pauseMenuModel);
  void parse(InputState inputState) override ;

private:
  PauseMenuModel *d_pauseMenuModel;
};

#endif /* PAUSE_MENU_INPUT_PARSER_H */