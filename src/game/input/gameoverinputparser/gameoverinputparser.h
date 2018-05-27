#ifndef GAME_OVER_INPUT_PARSER_H
#define GAME_OVER_INPUT_PARSER_H

#include "gameoverinputparser.ih"

/**
 * Input parser related to the game over model.
 */
class GameOverInputParser : public InputParser
{
public:
  /**
   * Construct input parser.
   */
  explicit GameOverInputParser(GameOverModel &gameOverModel);

  /**
   * Parse input related to the game over model.
   */
  void parse(InputState inputState) override;

private:
  GameOverModel *d_gameOverModel;
};

#endif // GAME_OVER_INPUT_PARSER_H