#include "pausemenurenderer.ih"

PauseMenuRenderer::PauseMenuRenderer(TextureFactory &textureFactory, PauseMenuModel &pauseMenuModel)
  : d_pauseMenuModel(&pauseMenuModel)
{
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
