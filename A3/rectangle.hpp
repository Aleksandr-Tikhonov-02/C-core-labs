#ifndef _RECTANGLE_
#define _RECTANGLE_

#include "base-types.hpp"
#include "shape.hpp"

namespace tikhonov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t& dot, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newDot) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;
  private:
    double width_;
    double height_;
    point_t dot_;
  };
}

#endif
