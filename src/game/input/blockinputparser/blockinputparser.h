#ifndef BLOCK_INPUT_PARSER_H
#define BLOCK_INPUT_PARSER_H

#include "blockinputparser.ih"

class BlockInputParser : public InputParser
{
public:
  explicit BlockInputParser(BlockModel *blockModel);
  void parse(InputState inputState) override;

private:
  BlockModel *d_blockModel;
};

#endif /* BLOCK_INPUT_PARSER_H */
