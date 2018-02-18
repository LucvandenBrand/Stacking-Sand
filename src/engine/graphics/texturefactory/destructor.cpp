#include "texturefactory.ih"

TextureFactory::~TextureFactory()
{
  this->d_textureCache.clear();
}
