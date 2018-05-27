#ifndef BLOCK_AUDIO_H
#define BLOCK_AUDIO_H

#include "blockaudio.ih"

/**
 * Plays the audio for the block model.
 */
class BlockAudio : public GameAudio
{
public:
  /**
   * Construct audio player for the block model.
   */
  explicit BlockAudio(AudioFactory &audioFactory, BlockModel &blockModel);

  /**
   * Update audio player state.
   */
  void update(double deltaTime) override;

private:
  shared_ptr<Sound> d_placeSound;
  BlockModel *d_blockModel;

  // Ensure we only play it once.
  bool d_playedPlace = false;
};

#endif // BLOCK_AUDIO_H