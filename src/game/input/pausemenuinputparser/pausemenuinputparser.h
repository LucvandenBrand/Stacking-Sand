#ifndef PAUSE_MENU_INPUT_PARSER_H
#define PAUSE_MENU_INPUT_PARSER_H

#include "pausemenuinputparser.ih"

/**
 * Input parser related to the pause menu model.
 */
class PauseMenuInputParser : public InputParser
{
public:
  /**
   * Construct the input parser.
   */
  explicit PauseMenuInputParser(PauseMenuModel &pauseMenuModel);

  /**
   * Parse input related to the pause menu model.
   */
  void parse(InputState inputState) override ;

private:
  PauseMenuModel *d_pauseMenuModel;
};

#endif // PAUSE_MENU_INPUT_PARSER_H