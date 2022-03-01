#include "Shape.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/io/ios_state.hpp>
#include "utils.hpp"

std::istream& tikhonov::operator>>(std::istream& in, Shape& shape)
{
  std::istream::sentry sentry(in);
  if (sentry) 
  {
    boost::io::ios_flags_saver guard(in);
    size_t vertices = 0;
    in >> std::noskipws >> std::ws >> vertices;
    if (vertices == 0)
    {
      in.setstate(std::istream::failbit);
    }
    if (!in)
    {
      return in;
    }
    Shape tempShape;
    std::copy_n(std::istream_iterator<Point>(in), vertices, std::back_inserter(tempShape));
    if (in.eof() || (vertices != tempShape.size()))
    {
      in.setstate(std::istream::failbit);
    }
    if (in)
    {
      shape = std::move(tempShape);
    }
  }
  return in;
}

std::istream& tikhonov::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    boost::io::ios_flags_saver guard(in);
    in >> std::noskipws;
    in >> skipSpaces >> Delimeter('(') >> skipSpaces >> point.x >> skipSpaces >> Delimeter(';') >> skipSpaces >> point.y
      >> skipSpaces >> Delimeter(')');
    if (!in)
    {
      in.setstate(std::istream::failbit);
    }
  }
  return in;
}

std::ostream& tikhonov::operator<<(std::ostream& out, const Shape& shape)
{
  std::ostream::sentry sentry(out);
  if (sentry)
  {
    out << shape.size() << ' ';
    std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out, " "));
  }
  return out;
}

std::ostream& tikhonov::operator<<(std::ostream& out, const Point& point)
{
  std::ostream::sentry sentry(out);
  if (sentry)
  {
    out << '(' << point.x << "; " << point.y << ')';
  }
  return out;
}

bool tikhonov::isTriangle(const Shape& shape)
{
  return shape.size() == 3;
}

bool tikhonov::isSquare(const Shape& shape)
{
  if (!isRectangle(shape))
  {
    return false;
  }
  size_t side1 = getSquaredDistance(shape[0], shape[1]);
  size_t side2 = getSquaredDistance(shape[1], shape[2]);
  return side1 == side2;
}

bool tikhonov::isRectangle(const Shape& shape)
{
  if (shape.size() != 4) 
  {
    return false;
  }
  double side1 = getSquaredDistance(shape[0], shape[1]);
  double side2 = getSquaredDistance(shape[1], shape[2]);
  double side3 = getSquaredDistance(shape[2], shape[3]);
  double side4 = getSquaredDistance(shape[3], shape[0]);
  double diagonal02 = getSquaredDistance(shape[0], shape[2]);
  double diagonal13 = getSquaredDistance(shape[1], shape[3]);
  if ((side1 + side2 == diagonal02) &&
    (side2 + side3 == diagonal13) &&
    (side3 + side4 == diagonal02)) 
  {
    return true;
  }
  return false;
}

bool tikhonov::isPentagon(const Shape& shape)
{
  return shape.size() == 5;
}

size_t tikhonov::getSquaredDistance(const Point& p1, const Point& p2)
{
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
