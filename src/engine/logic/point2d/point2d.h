#ifndef POINT2D_H
#define POINT2D_H

/**
 * Class for representing a point in 2D space.
 */
class Point2D
{
public:
  /**
   * Construct a point at (0, 0).
   */
  Point2D();

  /**
   * Construct a point at (x, y).
   */
  Point2D(short x, short y);

  /**
   * Location of the point.
   */
  short x, y;

  /**
   * Add another point to this point.
   */
  Point2D& operator+=(const Point2D &other);

  /**
   * Add two points.
   */
  const Point2D operator+(const Point2D &other) const;

  /**
   * Multiply an integer with this point.
   */
  const Point2D operator*(const int &other) const;
};

#endif // POINT2D_H
