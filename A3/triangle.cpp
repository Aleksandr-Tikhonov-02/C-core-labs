#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include "base-types.hpp"

tikhonov::Triangle::Triangle(const point_t& dot1, const point_t& dot2, const point_t& dot3):
  dot1_(dot1),
  dot2_(dot2),
  dot3_(dot3)
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("The points do not form a triangle. This is a dot or a line");
  }
}

double tikhonov::Triangle::getArea() const
{
  double firstSide = getSide(dot1_, dot2_);
  double secondSide = getSide(dot2_, dot3_);
  double thirdSide = getSide(dot3_, dot1_);
  double semiP = (firstSide + secondSide + thirdSide) / 2;
  return sqrt(semiP * (semiP - firstSide) * (semiP - secondSide) * (semiP - thirdSide));
}

tikhonov::rectangle_t tikhonov::Triangle::getFrameRect() const
{
  double rightSideX = std::max({ dot1_.x, dot2_.x, dot3_.x });
  double leftSideX = std::min({ dot1_.x, dot2_.x, dot3_.x });
  double topSideY = std::max({ dot1_.y, dot2_.y, dot3_.y });
  double bottomSideY = std::min({ dot1_.y, dot2_.y, dot3_.y });
  return {rightSideX - leftSideX, topSideY - bottomSideY, getCentreDot()};
}

void tikhonov::Triangle::move(const point_t& newDot)
{
  point_t oldCentre = getCentreDot();
  move(newDot.x - oldCentre.x, newDot.y - oldCentre.y);
}

void tikhonov::Triangle::move(double dx, double dy)
{
  dot1_.x += dx;
  dot2_.x += dx;
  dot3_.x += dx;
  dot1_.y += dy;
  dot2_.y += dy;
  dot3_.y += dy;
}

void tikhonov::Triangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error! The factor cannot be negative or zero!");
  }
  point_t centre = getCentreDot();
  dot1_.x = (dot1_.x - centre.x) * coefficient + centre.x;
  dot1_.y = (dot1_.y - centre.y) * coefficient + centre.y;
  dot2_.x = (dot2_.x - centre.x) * coefficient + centre.x;
  dot2_.y = (dot2_.y - centre.y) * coefficient + centre.y;
  dot3_.x = (dot3_.x - centre.x) * coefficient + centre.x;
  dot3_.y = (dot3_.y - centre.y) * coefficient + centre.y;
}

double tikhonov::Triangle::getSide(const point_t& dot1, const point_t& dot2) const
{
  return (sqrt((dot1.x - dot2.x) * (dot1.x - dot2.x) + (dot1.y - dot2.y) * (dot1.y - dot2.y)));
}

tikhonov::point_t tikhonov::Triangle::getCentreDot() const
{
  return { (dot1_.x + dot2_.x + dot3_.x) / 3, (dot1_.y + dot2_.y + dot3_.y) / 3 };
}
