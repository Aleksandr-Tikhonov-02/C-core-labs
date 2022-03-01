#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include <iosfwd>
#include <vector>

namespace tikhonov 
{
  struct Point 
  {
    int x, y;
  };

  using Shape = std::vector<Point>;

  std::istream& operator>>(std::istream& in, Shape& shape);
  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Point& point);
  bool isTriangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isPentagon(const Shape& shape);

  size_t getSquaredDistance(const Point& p1, const Point& p2);
}

#endif
