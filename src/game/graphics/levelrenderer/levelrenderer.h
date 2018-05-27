#ifndef TEXT_BOX_RENDERER_H
#define TEXT_BOX_RENDERER_H

#include "levelrenderer.ih"

/**
 * Renders the game levels.
 */
class LevelRenderer : public GameRenderer
{
public:
  /**
   * Construct the renderer.
   */
  LevelRenderer(TextureFactory &textureFactory, LevelModel &levelModel);

  /**
   * Render a stack of newspapers.
   */
  void render(SDL_Renderer &sdlRenderer, double deltaTime) override;

private:
  bool initTextures(TextureFactory &textureFactory);
  vector<shared_ptr<Texture>> d_newspapers;
  LevelModel *d_levelModel;
};

#endif // TEXT_BOX_RENDERER_H