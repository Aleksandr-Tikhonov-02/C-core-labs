#ifndef _TRIANGLE_
#define _TRIANGLE_

#include "base-types.hpp"
#include "shape.hpp"

class Triangle: public Shape
{
public:
  Triangle(const point_t& dot1, const point_t& dot2, const point_t& dot3);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& newDot) override;
  void move(double dx, double dy) override;
private:
  point_t dot1_;
  point_t dot2_;
  point_t dot3_;
  double getSide(const point_t& dot1, const point_t& dot2) const;
  point_t getCentreDot(const point_t& dot1, const point_t& dot2, const point_t& dot3) const;
};

#endif
