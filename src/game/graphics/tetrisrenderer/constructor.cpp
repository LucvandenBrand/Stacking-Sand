#include "tetrisrenderer.ih"

TetrisRenderer::TetrisRenderer(TextureFactory &textureFactory, TetrisModel *tetrisModel)
  : GridRenderer(textureFactory),
    d_tetrisModel(tetrisModel),
    d_shadowBrush(ShadowBrush(BG_COLOR, SHADOW_SPREAD))
{
  try
  {
    this->d_background = textureFactory.renderTexture(1, 1);
    this->d_backgroundTile = &(textureFactory.texture("data/backgroundTile.png"));
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not load background texture: " << invalidArgument.what() << endl;
  }
  catch(runtime_error &runtimeError)
  {
    cout << "Could not create background texture: " << runtimeError.what() << endl;
  }

}
