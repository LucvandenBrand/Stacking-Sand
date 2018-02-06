#include "painter.ih"

bool Painter::initTextures()
{
  // Try to load the textures.
  try
  {
    // Block textures
    this->d_blockTextures.reserve(2);
    this->d_blockTextures.push_back(*(new Texture(this->d_renderer, "data/sand.png")));
    this->d_blockTextures.push_back(*(new Texture(this->d_renderer, "data/stone.png")));

    // Escape key to quit texture.
    this->d_escapeKeyTexture = new Texture(this->d_renderer, "data/quitkey.png");

    // Make TetrisGrid texture to draw on.
    Grid tetrisGrid = this->d_tetris->grid();
    int gridHeightRatio = this->c_SCREEN_HEIGHT / tetrisGrid.height();
    int gridWidth = gridHeightRatio * tetrisGrid.width();
    this->d_gridTexture = new Texture(this->d_renderer, gridWidth,
                                      this->c_SCREEN_HEIGHT,
                                      SDL_TEXTUREACCESS_TARGET);
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
