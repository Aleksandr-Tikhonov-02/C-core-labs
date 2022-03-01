#include "circle.hpp"
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>
#include "base-types.hpp"

tikhonov::Circle::Circle(const point_t& dot, double radius) :
  radius_(radius),
  dot_(dot)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius is incorrect");
  }
}

double tikhonov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

tikhonov::rectangle_t tikhonov::Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, dot_ };
}

void tikhonov::Circle::move(const point_t& newDot)
{
  dot_ = newDot;
}

void tikhonov::Circle::move(double dx, double dy)
{
  dot_.x += dx;
  dot_.y += dy;
}

void tikhonov::Circle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient must be bigger than 0");
  }
  radius_ *= coefficient;
}
