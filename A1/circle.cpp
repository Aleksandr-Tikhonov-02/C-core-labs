#include "circle.hpp"
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>
#include "base-types.hpp"

Circle::Circle(const point_t& dot, double radius):
  radius_(radius),
  dot_(dot)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius is incorrect");
  }
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, dot_};
}

void Circle::move(const point_t& newDot)
{
  dot_ = newDot;
}

void Circle::move(double dx, double dy)
{
  dot_.x += dx;
  dot_.y += dy;
}
