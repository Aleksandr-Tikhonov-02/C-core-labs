#ifndef _SHAPE_
#define _SHAPE_

struct rectangle_t;
struct point_t;

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t& newDot) = 0;
  virtual void move(double dx, double dy) = 0;
};

#endif
