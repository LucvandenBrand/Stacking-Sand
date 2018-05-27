#ifndef BLOCK_INPUT_PARSER_H
#define BLOCK_INPUT_PARSER_H

#include "blockinputparser.ih"

/**
 * Parse input related to a block model.
 */
class BlockInputParser : public InputParser
{
public:
  /**
   * Construct an input parser.
   */
  explicit BlockInputParser(BlockModel &blockModel);

  /**
   * Parse input related to the block model.
   */
  void parse(InputState inputState) override;

private:
  BlockModel *d_blockModel;
};

#endif // BLOCK_INPUT_PARSER_H
