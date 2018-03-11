#include "blockaudio.ih"

BlockAudio::BlockAudio(AudioFactory &audioFactory, BlockModel &blockModel)
  : d_blockModel(&blockModel)
{
  try
  {
    d_placeSound = audioFactory.sound("data/place.wav");
  }
  catch (invalid_argument &invalidArgument)
  {
    cout << "Could not load sound:" << invalidArgument.what() << endl;
  }
}