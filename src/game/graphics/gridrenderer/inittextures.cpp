#include "gridrenderer.ih"

bool GridRenderer::initTextures(TextureFactory &textureFactory)
{
  // Try to load the cell textures.
  try
  {
    d_cellTextures.reserve(9);
    d_cellTextures.push_back(textureFactory.texture("data/sand.png"));
    d_cellTextures.push_back(textureFactory.texture("data/stone.png"));
    d_cellTextures.push_back(textureFactory.texture("data/diamond.png"));
    d_cellTextures.push_back(textureFactory.texture("data/plant.png"));
    d_cellTextures.push_back(textureFactory.texture("data/coal.png"));
    d_cellTextures.push_back(textureFactory.texture("data/lava.png"));
    d_cellTextures.push_back(textureFactory.texture("data/glass.png"));
    d_cellTextures.push_back(textureFactory.texture("data/coalFire.png"));
    d_cellTextures.push_back(textureFactory.texture("data/ice.png"));
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not load texture: " << invalidArgument.what() << endl;
    return false;
  }
  catch(runtime_error &runtimeError)
  {
    cout << "Could not create texture: " << runtimeError.what() << endl;
    return false;
  }

  // All went well, return success.
  return true;
}
