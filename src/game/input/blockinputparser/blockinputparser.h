#ifndef BLOCK_INPUT_PARSER_H
#define BLOCK_INPUT_PARSER_H

#include "blockinputparser.ih"

class BlockInputParser : public InputParser
{
public:
  BlockInputParser(BlockModel *blockModel);
  void parse(InputState inputState) override;

private:
  BlockModel *d_blockModel;
};

#endif /* BLOCK_INPUT_PARSER_H */
