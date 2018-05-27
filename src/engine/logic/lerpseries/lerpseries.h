#ifndef LERP_SERIES_H
#define LERP_SERIES_H

#include "lerpseries.ih"

/**
 * Contains a series of values in time that can be linearly interpolated.
 */
class LerpSeries {
public:
  /**
   * On constructing there must be a starting point.
   */
  explicit LerpSeries(double value);

  /**
   * Construct series with a beginning value of 0.
   */
  LerpSeries();

  /**
   * Update the internal clock.
   */
  void update(double deltaTime);

  /**
   * Reset the time to 0.
   */
  void reset();

  /**
   * Add a new point to the time series.
   */
  void add(double time, double value);

  /**
   * Get a linearly interpolated value.
   */
  double get();

  /**
   * Set whether or not the series should reset at the end.
   */
  void setLooping(bool loop);

private:
  bool d_loop = false;
  double d_time;
  map<double, double, less<>> d_timeSeries;
};

#endif // LERP_SERIES_H