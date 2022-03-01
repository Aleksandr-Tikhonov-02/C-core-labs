#ifndef _STRING_CONVERISON_
#define _STRING_CONVERISON_

#include <sstream>
#include <stdexcept>

namespace tikhonov
{
  template<typename T>
  T stringConversion(const char* src)
  {
    T tmp;
    std::istringstream buffer(src);
    buffer >> tmp;
    if (!buffer || !buffer.eof())
    {
      throw std::runtime_error("Incorrect imput");
    }
    return tmp;
  }
}

#endif
