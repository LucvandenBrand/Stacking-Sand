#ifndef TETRIS_INPUT_PARSER_H
#define TETRIS_INPUT_PARSER_H

#include "tetrisinputparser.ih"

class TetrisInputParser : public InputParser
{
public:
  explicit TetrisInputParser(TetrisModel &tetrisModel);
  void parse(InputState inputState) override ;

private:
  /* Game-play constants. */
  const double SPEEDUP_TIME = 0.05;

  TetrisModel *d_tetrisModel;
};

#endif /* TETRIS_INPUT_PARSER_H */
