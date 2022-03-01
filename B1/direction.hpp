#ifndef _DIRECTION_HPP_
#define _DIRECTION_HPP_

#include <iosfwd>

namespace tikhonov
{
  enum class Direction
  {
    ASCENDING,
    DESCENDING
  };

  Direction getDirection(const char* direction);
}

#endif
