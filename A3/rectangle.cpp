#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

tikhonov::Rectangle::Rectangle(const point_t& dot, double width, double height) :
  width_(width),
  height_(height),
  dot_(dot)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Width or height are incorrect");
  }
}

double tikhonov::Rectangle::getArea() const
{
  return width_ * height_;
}

tikhonov::rectangle_t tikhonov::Rectangle::getFrameRect() const
{
  return { width_, height_, dot_ };
}

void tikhonov::Rectangle::move(const point_t& newDot)
{
  dot_ = newDot;
}

void tikhonov::Rectangle::move(double dx, double dy)
{
  dot_.x += dx;
  dot_.y += dy;
}

void tikhonov::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error! The factor cannot be negative or zero!");
  }
  height_ *= coefficient;
  width_ *= coefficient;
}
