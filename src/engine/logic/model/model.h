#ifndef MODEL_H
#define MODEL_H

class Model
{
public:
  virtual void step(double deltaTime) = 0;

  /* Used by game to determine if it should close, returns true by default. */
  bool alive();

  /* Ask the game to close. */
  void kill();

private:
  bool d_alive = true;
};

#endif /* MODEL_H */
