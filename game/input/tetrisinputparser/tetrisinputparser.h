#ifndef TETRISINPUTPARSER_H
#define TETRISINPUTPARSER_H

#include "tetrisinputparser.ih"

class TetrisInputParser : public InputParser
{
public:
  TetrisInputParser(TetrisModel *tetrisModel);
  void parse(ButtonState buttonState);

private:
  TetrisModel *d_tetrisModel;
};

#endif /* TETRISINPUTPARSER_H */
