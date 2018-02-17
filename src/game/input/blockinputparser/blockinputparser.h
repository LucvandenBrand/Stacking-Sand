#ifndef BLOCKINPUTPARSER_H
#define BLOCKINPUTPARSER_H

#include "blockinputparser.ih"

class BlockInputParser : public InputParser
{
public:
  BlockInputParser(BlockModel *blockModel);
  void parse(ButtonState buttonState);

private:
  BlockModel *d_blockModel;
};

#endif /* BLOCKINPUTPARSER_H */
