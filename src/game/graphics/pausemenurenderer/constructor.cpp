#include "pausemenurenderer.ih"

PauseMenuRenderer::PauseMenuRenderer(TextureFactory &textureFactory, PauseMenuModel &pauseMenuModel)
  : d_pauseMenuModel(&pauseMenuModel),
    d_titleAnimation(LerpSeries(-1)),
    d_startButtonAnimation(LerpSeries(-2 * ANIM_WIGGLE))
{
  // Define the title animation.
  d_titleAnimation.add(1.0,  0);

  d_startButtonAnimation.add(0.6, ANIM_WIGGLE);
  d_startButtonAnimation.add(0.7, -2 * ANIM_WIGGLE);
  d_startButtonAnimation.setLooping(true);

  d_pauseButtonAnimation.add(0.1, ANIM_STRETCH);
  d_pauseButtonAnimation.add(0.2, 0);

  // Load graphics.
  try
  {
    d_gameTitle = textureFactory.texture("data/gameTitle.png");
    d_startControls = textureFactory.texture("data/startControls.png");
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not load gameTitle texture: " << invalidArgument.what() << endl;
  }

  // Try to load font.
  d_creditFont = nullptr;
  d_creditFont = TTF_OpenFont("data/creditFont.ttf", 80);
  if (d_creditFont == nullptr)
  {
    cout << "Failed to load creditFont!" << '\n';
  }
}
