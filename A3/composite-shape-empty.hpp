#ifndef _COMPOSITE_SHAPE_EMPTY_
#define _COMPOSITE_SHAPE_EMPTY_

#include <stdexcept>

namespace tikhonov
{
  class CompositeShapeIsEmpty : public std::exception
  {
  public:
    explicit CompositeShapeIsEmpty(const char* msg):
      msg_(msg)
    {}
    const char* what() const noexcept override
    {
      return msg_;
    }
  private:
    const char* msg_;
  };
}

#endif
