#include "levelrenderer.ih"

bool LevelRenderer::initTextures(TextureFactory &textureFactory)
{
  // Try to load the newspaper textures.
  try
  {
    d_newspapers.reserve(2);
    d_newspapers.push_back(textureFactory.texture("data/level0.png"));
    d_newspapers.push_back(textureFactory.texture("data/level1.png"));
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
