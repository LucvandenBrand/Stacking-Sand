#include "pausemenurenderer.ih"

PauseMenuRenderer::PauseMenuRenderer(TextureFactory &textureFactory, PauseMenuModel &pauseMenuModel)
  : d_pauseMenuModel(&pauseMenuModel),
    d_titleAnimation(LerpSeries(-1))
{
  // Define the title animation.
  d_titleAnimation.add(1.0,  0);

  // Load graphics.
  try
  {
    d_gameTitle = textureFactory.texture("data/gameTitle.png");
    d_startControls = textureFactory.texture("data/startControls.png");
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not load gameTitle texture: " << invalidArgument.what() << endl;
  }
}
