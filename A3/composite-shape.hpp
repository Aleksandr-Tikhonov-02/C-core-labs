#ifndef _COMPOSITE_SHAPE_
#define _COMPOSITE_SHAPE_

#include <memory>
#include "base-types.hpp"
#include "shape.hpp"

namespace tikhonov
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept = default;
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept = default;

    const std::shared_ptr<Shape>& operator[](size_t index) const;
    double getArea() const;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t& newDot) override;
    void scale(double coefficient) override;
    void add(const std::shared_ptr<Shape>& object);
    void remove(size_t index);
  private:
    size_t capacity_;
    size_t count_;
    std::unique_ptr<std::shared_ptr<Shape>[]> shapes_;
  };
}

#endif
