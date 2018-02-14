#include "gridrenderer.ih"

bool GridRenderer::initTextures(SDL_Renderer *sdlRenderer)
{
  // Try to load the cell textures.
  try
  {
    this->d_cellTextures.reserve(2);
    this->d_cellTextures.push_back(*(new Texture(sdlRenderer, "data/sand.png")));
    this->d_cellTextures.push_back(*(new Texture(sdlRenderer, "data/stone.png")));
  }
  catch (invalid_argument invarg)
  {
    cout << "Could not load texture: " << invarg.what() << endl;
    return false;
  }
  catch(runtime_error runerr)
  {
    cout << "Could not create texture: " << runerr.what() << endl;
    return false;
  }

  // All went well, return success.
  return true;
}
