#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
private:
  unsigned short d_x, d_y;
public:
  Point2D(unsigned short x, unsigned short y);

  // Return the coordinates of this point.
  unsigned short x();
  unsigned short y();

  // Change the coordinates of this point.
  void x(unsigned short newX);
  void y(unsigned short newY);
};

#endif // POINT2D_H
