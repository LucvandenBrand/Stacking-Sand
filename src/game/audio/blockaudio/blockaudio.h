#ifndef BLOCK_AUDIO_H
#define BLOCK_AUDIO_H

#include "blockaudio.ih"

class BlockAudio : public GameAudio
{
public:
  explicit BlockAudio(AudioFactory &audioFactory, BlockModel &blockModel);
  void update(double deltaTime) override;

private:
  shared_ptr<Sound> d_placeSound;
  BlockModel *d_blockModel;

  // Ensure we only play it once.
  bool d_playedPlace = false;
};

#endif /* BLOCK_AUDIO_H */