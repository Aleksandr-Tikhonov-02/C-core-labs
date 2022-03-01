#ifndef _CIRCLE_
#define _CIRCLE_

#include "base-types.hpp"
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t& dot, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& newDot) override;
  void move(double dx,double dy) override;
private:
  double radius_;
  point_t dot_;
};

#endif
