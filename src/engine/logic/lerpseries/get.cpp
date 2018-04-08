#include "lerpseries.ih"

double LerpSeries::get()
{
  // Get closest time-value below and after current time.
  double start = 0, end = 0;
  for(auto const & timeValue : d_timeSeries)
  {
    end = timeValue.first;
    if (end > d_time)
      break;
    start = end;
  }

  // We passed the last point, so no lerp.
  if (start == end)
    return d_timeSeries[end];

  // Get difference in time between time-values.
  double duration = end - start;
  double dStart = 1 - (d_time - start) / duration,
         dEnd   = 1 - dStart;

  // Mix values, return value.
  return dStart * d_timeSeries[start] + dEnd * d_timeSeries[end];
}