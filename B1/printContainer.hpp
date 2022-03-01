#ifndef _PRINT_
#define _PRINT_

#include <ostream>

namespace tikhonov
{
  template<typename Iterator>
  void print(Iterator begin, Iterator end, std::ostream& out)
  {
    bool isEmpty = true;
    if (begin != end)
    {
      out << *begin;
      ++begin;
      isEmpty = false;
    }
    while (begin != end)
    {
      out << ' ' << *begin;
      ++begin;
    }
    if (!isEmpty)
    {
      out << '\n';
    }
  }
}

#endif
