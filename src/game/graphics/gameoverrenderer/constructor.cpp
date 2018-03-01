#include "gameoverrenderer.ih"

GameOverRenderer::GameOverRenderer(TextureFactory &textureFactory, GameOverModel *gameOverModel)
  : d_gameOverModel(gameOverModel)
{
  try
  {
    d_gameOverTexture  = &(textureFactory.texture("data/gameOver.png"));
    d_gameOverControls = &(textureFactory.texture("data/gameOverControls.png"));
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not render game over texture: " << invalidArgument.what() << endl;
  }

}