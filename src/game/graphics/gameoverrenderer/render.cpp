#include "gameoverrenderer.ih"

void GameOverRenderer::render(SDL_Renderer &sdlRenderer)
{
  if (d_gameOverModel->gameOver())
  {
    /* Create a dark rectangle over the screen. */
    ScreenNormalizer normalizer(sdlRenderer);
    auto opacity = (Uint8) (230 * d_gameOverModel->gameOverTransition());
    SDL_SetRenderDrawColor(&sdlRenderer, 0, 0, 0, opacity);
    SDL_Rect fillRectangle = normalizer.deNormalize(0, 0, 1, 1);
    SDL_RenderFillRect(&sdlRenderer, &fillRectangle);

    /* Render the the news of you going game over. */
    float newsHeight = 0.8f;
    float newsWidth = newsHeight / normalizer.normalizeHeight(d_gameOverTexture->height())
                                 * normalizer.normalizeWidth(d_gameOverTexture->width());
    float newsX = 0.5f - newsWidth / 2;
    float newsY = 0.45f - newsHeight / 2 + (1 - d_gameOverModel->gameOverTransition());
    SDL_Rect newsRectangle = normalizer.deNormalize(newsX, newsY, newsWidth, newsHeight);
    d_gameOverTexture->render(sdlRenderer, newsRectangle);

    /* Render the game over controls. */
    float controlWidth = newsWidth * 0.6f;
    float controlHeight = controlWidth / normalizer.normalizeWidth(d_gameOverControls->width())
                                       * normalizer.normalizeHeight(d_gameOverControls->height());
    float controlX = 0.5f - controlWidth / 2;
    float controlY = 0.97f - controlHeight + (1 - d_gameOverModel->gameOverTransition());
    SDL_Rect controlRectangle = normalizer.deNormalize(controlX, controlY, controlWidth, controlHeight);
    d_gameOverControls->render(sdlRenderer, controlRectangle);
  }
}