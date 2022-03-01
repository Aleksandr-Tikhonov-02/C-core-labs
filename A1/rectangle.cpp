#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

Rectangle::Rectangle(const point_t& dot, double width, double height):
  width_(width),
  height_(height),
  dot_(dot)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Width or height are incorrect");
  }
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, dot_};
}

void Rectangle::move(const point_t& newDot)
{
  dot_ = newDot;
}

void Rectangle::move(double dx, double dy)
{
  dot_.x += dx;
  dot_.y += dy;
}
