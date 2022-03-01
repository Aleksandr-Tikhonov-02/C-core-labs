#ifndef _B5_UTILS_
#define _B5_UTILS_

#include <iosfwd>

namespace tikhonov
{
  struct Delimeter
  {
    Delimeter(char delimeter):
      delimeter_(delimeter)
    {}
    char delimeter_;
  };

  std::istream& operator>>(std::istream& in, Delimeter&& delim);
  std::istream& skipSpaces(std::istream& in);
}
#endif 
