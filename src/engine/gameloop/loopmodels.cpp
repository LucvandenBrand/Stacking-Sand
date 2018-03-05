#include "gameloop.ih"

void GameLoop::loopModels(vector<Model*> models)
{
  auto waitTime = chrono::milliseconds(UPDATE_SPEED_MODELS);
  double deltaTime = 1.0 * waitTime.count() / MILLI_IN_SECONDS;

  while(d_running)
  {
    // Destroy all dead models.
    models.erase(remove_if(models.begin(), models.end(),
                           [](Model *model){return !(model->alive());}), models.end());

    // Update all living models.
    for (Model *model : models)
      model->step(deltaTime);


    // We quit if there are no models.
    d_running = !models.empty();

    // Sleep
    this_thread::sleep_for(waitTime);
  }
}
