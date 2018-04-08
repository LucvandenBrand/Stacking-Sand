#ifndef LERP_SERIES_H
#define LERP_SERIES_H

#include "lerpseries.ih"

class LerpSeries {
public:
  /* On constructing there must be a starting point. */
  explicit LerpSeries(double value);
  LerpSeries();

  /* Update the internal clock. */
  void update(double deltaTime);

  /* Reset the time to 0. */
  void reset();

  /* Add a new point to the time series. */
  void add(double time, double value);

  /* Get a linearly interpolated value. */
  double get();

private:
  double d_time;
  map<double, double, less<>> d_timeSeries;
};

#endif /* LERP_SERIES_H */