#ifndef GAME_OVER_MODEL_H
#define GAME_OVER_MODEL_H

#include "gameovermodel.ih"

/**
 * Controls the state of a game-over.
 */
class GameOverModel: public Model
{
public:
  /**
   * Constructs a model handling the game-over state.
   */
  GameOverModel(TetrisModel &tetrisModel, BlockModel &blockModel);

  /**
   * Update the state.
   */
  void step(double deltaTime) override;

  /**
   * Is the game in failed state?
   */
  bool gameOver();

  /**
   * Reset the game.
   */
  void reset();

  /**
   * How far to slide the game-over message.
   */
  double gameOverTransition();

private:
  TetrisModel *d_tetrisModel;
  BlockModel *d_blockModel;

  double d_gameOverTransition;
  const double SCALE_TRANSITION = 0.5;
};

#endif // GAME_OVER_MODEL_H