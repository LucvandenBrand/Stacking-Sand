#include "blockrenderer.ih"

BlockRenderer::BlockRenderer(TextureFactory &textureFactory, BlockModel &blockModel)
  : GridRenderer(textureFactory),
    d_blockModel(&blockModel),
    d_shadowBrush(ShadowBrush(SHADOW_COLOR, SHADOW_SPREAD))
{
  try
  {
    d_controlImage = textureFactory.texture("data/controls.png");
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not control texture: " << invalidArgument.what() << endl;
  }
}
