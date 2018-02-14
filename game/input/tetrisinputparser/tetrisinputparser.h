#ifndef TETRISINPUTPARSER_H
#define TETRISINPUTPARSER_H

#include "tetrisinputparser.ih"

class TetrisInputParser : public InputParser
{
public:
  TetrisInputParser(TetrisModel *tetrisModel);
  void parse(ButtonState buttonState);

private:
  /* Gameplay constants. */
  const float SPEEDUP_TIME = 0.5f;

  TetrisModel *d_tetrisModel;
};

#endif /* TETRISINPUTPARSER_H */
