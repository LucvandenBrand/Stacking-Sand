#include "tetrisrenderer.ih"

TetrisRenderer::TetrisRenderer(TextureFactory &textureFactory, TetrisModel &tetrisModel)
  : GridRenderer(textureFactory),
    d_tetrisModel(&tetrisModel),
    d_shadowBrush(ShadowBrush(BG_COLOR, SHADOW_SPREAD))
{
  try
  {
    d_background = textureFactory.renderTexture(1, 1);
    d_backgroundTile = textureFactory.texture("data/backgroundTile.png");
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not load background texture: " << invalidArgument.what() << endl;
  }
  catch(runtime_error &runtimeError)
  {
    cout << "Could not create background texture: " << runtimeError.what() << endl;
  }

  // Try to load font.
  d_gameFont = nullptr;
  d_gameFont = TTF_OpenFont("data/gameFont.ttf", 80);
  if (d_gameFont == nullptr)
  {
    cout << "Failed to load gameFont!" << '\n';
  }
}
