#ifndef _DATA_STRUCT_
#define _DATA_STRUCT_

#include <string>
#include <iosfwd>

namespace tikhonov
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  struct Delimeter
  {};

  const int MAX_KEY_VALUE = 5;
  std::istream& operator>>(std::istream& in, DataStruct& dstruct);
  std::ostream& operator<<(std::ostream& out, const DataStruct& dstruct);
  std::istream& operator>>(std::istream& in, Delimeter&&);
  std::istream& skipSpaces(std::istream& in);
}

#endif
