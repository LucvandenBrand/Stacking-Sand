#include "blockaudio.ih"

void BlockAudio::update(double deltaTime)
{
  if (d_blockModel->placed() && !d_playedPlace)
  {
    d_placeSound.get()->play();
    d_playedPlace = true;
  }
  else if (!d_blockModel->placed())
    d_playedPlace = false;
}