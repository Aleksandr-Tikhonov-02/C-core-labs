#include "task1.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <forward_list>
#include "sort.hpp"
#include "sortTools.hpp"
#include "printContainer.hpp"
#include "direction.hpp"

void tikhonov::task1(const char* directionstr, std::istream& in, std::ostream& out)
{
  Direction direction = getDirection(directionstr);
  std::vector<int> source;
  while (in)
  {
    int element = 0;
    in >> element;
    if (in.eof())
    {
      break;
    }
    if (in.fail())
    {
      throw std::invalid_argument("Incorrect data");
    }
    source.push_back(element);
  }
  if (source.empty())
  {
    return;
  }
  std::vector<int> sourceCopy(source);
  std::forward_list<int> listSourceCopy(source.begin(), source.end());

  tikhonov::sort<tikhonov::Index, std::vector<int>>(source, direction);
  tikhonov::print(source.cbegin(), source.cend(), out);

  tikhonov::sort<tikhonov::At, std::vector<int>>(sourceCopy, direction);
  tikhonov::print(sourceCopy.cbegin(), sourceCopy.cend(), out);

  tikhonov::sort<tikhonov::Iterator, std::forward_list<int>>(listSourceCopy, direction);
  tikhonov::print(listSourceCopy.cbegin(), listSourceCopy.cend(), out);
}
