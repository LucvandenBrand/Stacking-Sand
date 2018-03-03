#ifndef GAME_OVER_INPUT_PARSER_H
#define GAME_OVER_INPUT_PARSER_H

#include "gameoverinputparser.ih"

class GameOverInputParser : public InputParser
{
public:
  explicit GameOverInputParser(GameOverModel &gameOverModel);
  void parse(InputState inputState) override;

private:
  GameOverModel *d_gameOverModel;
};

#endif /* GAME_OVER_INPUT_PARSER_H */