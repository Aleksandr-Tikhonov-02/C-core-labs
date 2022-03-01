#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include "base-types.hpp"

Triangle::Triangle(const point_t& dot1, const point_t& dot2, const point_t& dot3):
  dot1_(dot1),
  dot2_(dot2),
  dot3_(dot3)
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("The points do not form a triangle. This is a dot or a line");
  }
}

double Triangle::getArea() const
{
  double firstSide = getSide(dot1_, dot2_);
  double secondSide = getSide(dot2_, dot3_);
  double thirdSide = getSide(dot3_, dot1_);
  double semiP = (firstSide + secondSide + thirdSide) / 2;
  return sqrt(semiP * (semiP - firstSide) * (semiP - secondSide) * (semiP - thirdSide));
}

rectangle_t Triangle::getFrameRect() const
{
  double rightSideX = std::max({dot1_.x, dot2_.x, dot3_.x});
  double leftSideX = std::min({dot1_.x, dot2_.x, dot3_.x});
  double topSideY = std::max({dot1_.y, dot2_.y, dot3_.y});
  double bottomSideY = std::min({dot1_.y, dot2_.y, dot3_.y});
  return {rightSideX - leftSideX, topSideY - bottomSideY, getCentreDot(dot1_, dot2_, dot3_)};
}

void Triangle::move(const point_t& newDot)
{
  point_t oldCenter = getCentreDot(dot1_, dot2_, dot3_);
  move(newDot.x - oldCenter.x, newDot.y - oldCenter.y);
}

void Triangle::move(double dx, double dy)
{
  dot1_.x += dx;
  dot2_.x += dx;
  dot3_.x += dx;
  dot1_.y += dy;
  dot2_.y += dy;
  dot3_.y += dy;
}

double Triangle::getSide(const point_t& dot1, const point_t& dot2) const
{
  return (sqrt((dot1.x - dot2.x) * (dot1.x - dot2.x) + (dot1.y - dot2.y) * (dot1.y - dot2.y)));
}

point_t Triangle::getCentreDot(const point_t& dot1, const point_t& dot2, const point_t& dot3) const
{
  return {(dot1.x + dot2.x + dot3.x) / 3, (dot1.y + dot2.y + dot3.y) / 3};
}
