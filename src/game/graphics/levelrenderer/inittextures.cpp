#include "levelrenderer.ih"

bool LevelRenderer::initTextures(TextureFactory &textureFactory)
{
  // Try to load the newspaper textures.
  try
  {
    const int NUM_PAPERS = 14;
    d_newspapers.reserve(NUM_PAPERS);
    for (int paper = 0; paper < NUM_PAPERS; paper++)
      d_newspapers.push_back(textureFactory.texture("data/level" + to_string(paper) + ".png"));
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
