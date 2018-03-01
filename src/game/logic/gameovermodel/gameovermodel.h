#ifndef GAME_OVER_MODEL_H
#define GAME_OVER_MODEL_H

#include "gameovermodel.ih"

class GameOverModel: public Model
{
public:
  GameOverModel(TetrisModel *tetrisModel, BlockModel *blockModel);

  // Update the state.
  void step(float deltaTime) override;

  // Is the game in failed state?
  bool gameOver();

  // Reset the game.
  void reset();

private:
  TetrisModel *d_tetrisModel;
  BlockModel *d_blockModel;
};

#endif /* GAME_OVER_MODEL_H */