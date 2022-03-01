#include "composite-shape.hpp"
#include <stdexcept>
#include <memory>
#include "base-types.hpp"
#include "composite-shape-empty.hpp"

tikhonov::CompositeShape::CompositeShape():
  capacity_(10),
  count_(0),
  shapes_(std::make_unique<std::shared_ptr<Shape>[]>(capacity_))
{}

tikhonov::CompositeShape::CompositeShape(const tikhonov::CompositeShape& other):
  capacity_(other.capacity_),
  count_(other.count_),
  shapes_(std::make_unique<std::shared_ptr<Shape>[]>(other.capacity_))
{
  for (size_t i = 0; i < other.count_; i++)
  {
    shapes_[i] = other.shapes_[i];
  }
}

tikhonov::CompositeShape& tikhonov::CompositeShape::operator=(const tikhonov::CompositeShape& other)
{
  if (this == &other)
  {
    return *this;
  }
  CompositeShape tmp(other);
  std::swap(capacity_, tmp.capacity_);
  std::swap(count_, tmp.count_);
  std::swap(shapes_, tmp.shapes_);
  return *this;
}

const std::shared_ptr<tikhonov::Shape>& tikhonov::CompositeShape::operator[](size_t index) const
{
  if (!shapes_)
  {
    throw std::runtime_error("Array was moved");
  }
  if (index >= count_)
  {
    throw std::out_of_range("Incorrect array index");
  }
  return shapes_[index];
}

double tikhonov::CompositeShape::getArea() const
{
  if (!shapes_)
  {
    throw std::runtime_error("Array was moved");
  }
  double area = 0;
  for (size_t i = 0; i < count_; i++)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}

tikhonov::rectangle_t tikhonov::CompositeShape::getFrameRect() const
{
  if (!shapes_)
  {
    throw std::runtime_error("Array was moved");
  }
  if (count_ == 0)
  {
    throw tikhonov::CompositeShapeIsEmpty("CompositeShape is empty");
  }
  double leftSideX = 0;
  double rightSideX = 0;
  double lowerSideY = 0;
  double topSideY = 0;
  size_t i = 0;
  for (; i < count_; i++)
  {
    try
    {
      rectangle_t frame = shapes_[i]->getFrameRect();
      leftSideX = frame.pos.x - frame.width / 2;
      rightSideX = frame.pos.x + frame.width / 2;
      lowerSideY = frame.pos.y - frame.height / 2;
      topSideY = frame.pos.y + frame.height / 2;
      break;
    }
    catch (const tikhonov::CompositeShapeIsEmpty& e)
    {}
  }
  if (i == count_)
  {
    throw tikhonov::CompositeShapeIsEmpty("CompositeShape contains of empty CompositeShapes");
  }
  for (i = i + 1; i < count_; i++)
  {
    try
    {
      rectangle_t frame = shapes_[i]->getFrameRect();
      leftSideX = std::min(leftSideX, frame.pos.x - frame.width / 2);
      rightSideX = std::max(rightSideX, frame.pos.x + frame.width / 2);
      lowerSideY = std::min(lowerSideY, frame.pos.y - frame.height / 2);
      topSideY = std::max(topSideY, frame.pos.y + frame.height / 2);
    }
    catch (const tikhonov::CompositeShapeIsEmpty& e)
    {
      continue;
    }
  }
  return { rightSideX - leftSideX, topSideY - lowerSideY, (rightSideX + leftSideX) / 2, (topSideY + lowerSideY) / 2 };
}

void tikhonov::CompositeShape::move(double dx, double dy)
{
  if (!shapes_)
  {
    throw std::runtime_error("Array was moved");
  }
  for (size_t i = 0; i < count_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void tikhonov::CompositeShape::move(const point_t& newDot)
{
  if (!shapes_)
  {
    throw std::runtime_error("Array was moved");
  }
  point_t oldDot = getFrameRect().pos;
  move(newDot.x - oldDot.x, newDot.y - oldDot.y);
}

void tikhonov::CompositeShape::scale(double coefficient)
{
  if (!shapes_)
  {
    throw std::runtime_error("Array was moved");
  }
  if (coefficient <= 0)
  {
    throw std::invalid_argument("coefficient is incorrect");
  }
  point_t compositeCentre = getFrameRect().pos;
  for (size_t i = 0; i < count_; i++)
  {
    shapes_[i]->scale(coefficient);
    point_t shapeCentre = shapes_[i]->getFrameRect().pos;
    shapes_[i]->move((shapeCentre.x - compositeCentre.x) * coefficient - (shapeCentre.x - compositeCentre.x),
                     (shapeCentre.y - compositeCentre.y) * coefficient - (shapeCentre.y - compositeCentre.y));
  }
}

void tikhonov::CompositeShape::add(const std::shared_ptr<Shape>& object)
{
  if (!shapes_)
  {
    throw std::runtime_error("Array was moved");
  }
  if (!object)
  {
    throw std::invalid_argument("Incorrect object");
  }
  if (count_ == capacity_)
  {
    std::unique_ptr<std::shared_ptr<Shape>[]> tmp = std::make_unique<std::shared_ptr<Shape>[]>(capacity_ * 2);
    for (size_t i = 0; i < count_; i++)
    {
      tmp[i] = shapes_[i];
    }
    capacity_ *= 2;
    std::swap(shapes_, tmp);
  }
  shapes_[count_] = object;
  count_++;
}

void tikhonov::CompositeShape::remove(size_t index)
{
  if (!shapes_)
  {
    throw std::runtime_error("Array was moved");
  }
  if (count_ == 0)
  {
    throw std::runtime_error("Composite shape underflow");
  }
  if (index >= count_)
  {
    throw std::out_of_range("Incorrect array index");
  }
  for (size_t i = index; i < count_ - 1; i++)
  {
    shapes_[i] = shapes_[i + 1];
  }
  count_--;
}
