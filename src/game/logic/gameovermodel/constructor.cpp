#include "gameovermodel.ih"

GameOverModel::GameOverModel(TetrisModel &tetrisModel, BlockModel &blockModel)
  : d_tetrisModel(&tetrisModel),
    d_blockModel(&blockModel),
    d_gameOverTransition(0)
{}