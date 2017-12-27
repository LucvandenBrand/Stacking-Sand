#ifndef GRIDSTAMP_H
#define GRIDSTAMP_H

#include "gridstamp.ih"

class GridStamp
{
private:
  Grid d_source;
public:
  GridStamp(Grid source);

  // Copy d_source onto destination at position.
  void stamp(Point2D position, Grid destination);;
};

#endif // GRIDSTAMP_H
