#ifndef MODEL_H
#define MODEL_H

/**
 * Holds behavior and data for an entity in the game.
 */
class Model
{
public:
  /**
   * Perform model logic for one frame step.
   */
  virtual void step(double deltaTime) = 0;

  /**
   * Used by game to determine if it should destroy the object, returns true by default.
   */
  bool alive();

  /**
   * Ask the object to be destroyed.
   */
  void kill();

private:
  bool d_alive = true;
};

#endif // MODEL_H
