#include "lerpseries.ih"

void LerpSeries::add(double time, double value)
{
  d_timeSeries[time] = value;
}