#include "task2.hpp"
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "Shape.hpp"

void tikhonov::task2(std::istream& in, std::ostream& out)
{
  std::list<Shape> shapes{ std::istream_iterator<Shape>(in), std::istream_iterator<Shape>() };
  if (in.fail() && !in.eof())
  {
    throw std::runtime_error("Reading error");
  }
  size_t vertices = std::accumulate(shapes.cbegin(), shapes.cend(), 0, [](int sum, const Shape& shape) 
    {
      return sum + shape.size();
    });
  size_t triangles = std::count_if(shapes.begin(), shapes.end(), isTriangle);
  size_t squares = std::count_if(shapes.begin(), shapes.end(), isSquare);
  size_t rectangles = std::count_if(shapes.begin(), shapes.end(), isRectangle);
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());
  std::vector<Point> points;
  std::transform(shapes.cbegin(), shapes.cend(), std::back_inserter(points), [](const Shape& shape) 
    {
      return shape[0];
    });
  shapes.sort([](Shape& shape1, Shape& shape2) 
    {
      if ((shape1.size() == 3) && (shape2.size() != 3)) 
      {
        return true;
      }
      else if (isSquare(shape1) && (shape2.size() >= 4)) 
      {
        return true;
      }
      return isRectangle(shape1) && (shape2.size() > 4);
    });
  out << "Vertices: " << vertices << "\nTriangles: " << triangles << "\nSquares: " << squares
    << "\nRectangles: " << rectangles << "\nPoints: ";
  std::copy(points.cbegin(), points.cend(), std::ostream_iterator<Point>(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator<Shape>(out, "\n"));
}
