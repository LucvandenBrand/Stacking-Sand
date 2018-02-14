#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
public:
  Point2D();
  Point2D(short x, short y);
  short x, y;

  // Adding another point to this point.
  Point2D& operator+=(const Point2D &other);

  // Adding two points.
  const Point2D operator+(const Point2D &other) const;

  // Multiplying an integer to the point.
  const Point2D operator*(const int &other) const;
};

#endif // POINT2D_H
