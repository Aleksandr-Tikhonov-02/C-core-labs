#include <iostream>
#include <memory>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "composite-shape.hpp"

void printArea(const tikhonov::Shape& shape);
void printFrameStatement(const tikhonov::Shape& shape);


int main()
{
  try
  {
    std::cout << "Rectangle:\n";
    tikhonov::Rectangle rectangle({ 1, 3 }, 6, 3);
    printArea(rectangle);
    printFrameStatement(rectangle);
    std::cout << "\tmove rectangle to (10, 10)\n";
    rectangle.move({ 10, 10 });
    printFrameStatement(rectangle);
    std::cout << "\tmove rectangle back to (1, 3)\n";
    rectangle.move(-9, -7);
    printFrameStatement(rectangle);

    std::cout << "Circle:\n";
    tikhonov::Circle circle({ 1.1, 2.2 }, 5);
    printArea(circle);
    printFrameStatement(circle);
    std::cout << "\tmove circle to (2.2, 3.3)\n";
    circle.move({ 2.2, 3.3 });
    printFrameStatement(circle);
    std::cout << "\tmove circle back to (1.1, 2.2)\n";
    circle.move(-1.1, -1.1);
    printFrameStatement(circle);

    std::cout << "Triangle:\n";
    tikhonov::Triangle triangle({ 0, 0 }, { 10, 0 }, { 5, 5 });
    printArea(triangle);
    printFrameStatement(triangle);
    std::cout << "\tmove circle to (2.2, 3.3)\n";
    triangle.move({ 2.2, 3.3 });
    printFrameStatement(triangle);
    std::cout << "\tmove circle to (1.1, 2.2)\n";
    triangle.move(-1.1, -1.1);
    printFrameStatement(triangle);

    std::cout << "Composite shape:\n";
    tikhonov::CompositeShape array;
    std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Circle>(circle);
    std::shared_ptr<tikhonov::Shape> second = std::make_shared<tikhonov::Rectangle>(rectangle);
    std::shared_ptr<tikhonov::Shape> third = std::make_shared<tikhonov::Triangle>(triangle);
    std::shared_ptr<tikhonov::Shape> fourth;
    std::shared_ptr<tikhonov::Shape> fifth;
    std::shared_ptr<tikhonov::Shape> sixth;
    fourth = std::make_shared<tikhonov::Circle>(tikhonov::point_t{ -6, -5 }, 10);
    fifth = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ -4, 7 }, 5, 5);
    sixth  = std::make_shared<tikhonov::Triangle>(tikhonov::point_t{ -15, 0 }, tikhonov::point_t{ -5, 0 }, tikhonov::point_t{ -10, 6 });
    array.add(first);
    array.add(second);
    array.add(third);
    array.add(fourth);
    array.add(fifth);
    array.add(sixth);
    printArea(array);
    std::cout << "\tremove fourth shape from our array\n";
    array.remove(3);
    printArea(array);
    printFrameStatement(array);
    std::cout << "\tmove CompositeShape to (0, 0)\n";
    array.move({ 0, 0 });
    printFrameStatement(array);
    std::cout << "\tmove CompositeShape to (10, -3)\n";
    array.move(10, -3);
    printFrameStatement(array);
    std::cout << "\tincrease all shapes by coef 2 \n";
    array.scale(2);
    printArea(array);
    printFrameStatement(array);
  }
  catch (const std::exception& exception)
  {
    std::cerr << '\n' << exception.what() << '\n';
    return 1;
  }
  return 0;
}

void printArea(const tikhonov::Shape& shape)
{
  std::cout << "\tArea: " << shape.getArea() << '\n';
}

void printFrameStatement(const tikhonov::Shape& shape)
{
  tikhonov::rectangle_t frame = shape.getFrameRect();
  std::cout << "\tframe statement: " << frame.width << "X" << frame.height << " "
            << "centre - (" << frame.pos.x << ";" << frame.pos.y << ")\n";
}
