#include "blockmodel.ih"

BlockModel::BlockModel(TetrisModel &tetrisModel)
  : d_tetrisModel(&tetrisModel),
    d_currentBlock(Grid(0,0)),
    d_nextBlock(Grid(0,0))
{
  // Initialise random seed.
  d_randomGenerator.seed((unsigned long) time(nullptr));

  // Initialize weights.
  vector<int> cellAvailability(tetrisModel.NUM_CELLS + 1, 0);
  cellAvailability[tetrisModel.AIR]       = 0;
  cellAvailability[tetrisModel.SAND]      = 40;
  cellAvailability[tetrisModel.STONE]     = 20;
  cellAvailability[tetrisModel.DIAMOND]   = 0;
  cellAvailability[tetrisModel.PLANT]     = 30;
  cellAvailability[tetrisModel.COAL]      = 0;
  cellAvailability[tetrisModel.LAVA]      = 5;
  cellAvailability[tetrisModel.GLASS]     = 0;
  cellAvailability[tetrisModel.COAL_FIRE] = 0;
  cellAvailability[tetrisModel.ICE]       = 5;
  d_cellAvailability = cellAvailability;

  // Choose the first block.
  d_nextBlock = generateBlock();

  // Set initial state.
  reset();
}
