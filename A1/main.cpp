#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void printArea(const Shape& shape);
void printFrameStatement(const Shape& shape);

int main()
{
  try
  {
    std::cout << "Rectangle:\n";
    Rectangle rectangle({1, 3}, 6, 3);
    printArea(rectangle);
    printFrameStatement(rectangle);
    std::cout << "\tmove rectangle to (10, 10)\n";
    rectangle.move({10, 10});
    printFrameStatement(rectangle);
    std::cout << "\tmove rectangle back to (1, 3)\n";
    rectangle.move(-9, -7);
    printFrameStatement(rectangle);
    std::cout << "Circle:\n";
    Circle circle({1.1, 2.2}, 5);
    printArea(circle);
    printFrameStatement(circle);
    std::cout << "\tmove circle to (2.2, 3.3)\n";
    circle.move({2.2, 3.3});
    printFrameStatement(circle);
    std::cout << "\tmove circle back to (1.1, 2.2)\n";
    circle.move(-1.1, -1.1);
    printFrameStatement(circle);
    std::cout << "Triangle:\n";
    Triangle triangle({0, 0}, {10, 0}, {5, 5});
    printArea(triangle);
    printFrameStatement(triangle);
    std::cout << "\tmove circle to (2.2, 3.3)\n";
    triangle.move({2.2, 3.3});
    printFrameStatement(triangle);
    std::cout << "\tmove circle back to (0, 0)\n";
    triangle.move(-2.2, -3.3);
    printFrameStatement(triangle);
  }
  catch (const std::invalid_argument& exception)
  {
    std::cerr << '\n' << exception.what() << '\n';
    return 1;
  }
  return 0;
}

void printArea(const Shape& shape)
{
  std::cout << "\tArea: " << shape.getArea() << '\n';
}

void printFrameStatement(const Shape& shape)
{
  rectangle_t frame = shape.getFrameRect();
  std::cout << "\tframe statement: " << frame.width << "X" << frame.height << " "
            << "centre - (" << frame.pos.x << ";" << frame.pos.y << ")\n";
}
