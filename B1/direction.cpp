#include "direction.hpp"
#include <stdexcept>
#include <cstring>

tikhonov::Direction tikhonov::getDirection(const char* direction)
{
  if (std::strcmp(direction, "ascending") == 0)
  {
    return Direction::ASCENDING;
  }
  else if (std::strcmp(direction, "descending") == 0)
  {
    return Direction::DESCENDING;
  }
  else
  {
    throw std::invalid_argument("Incorrect direction");
  }
}
