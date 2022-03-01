#include "task.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "DataStruct.hpp"

void tikhonov::task(std::istream& in, std::ostream& out)
{
  std::vector<tikhonov::DataStruct> vector
  { std::istream_iterator<tikhonov::DataStruct>(in), 
    std::istream_iterator<tikhonov::DataStruct>() };
  if (!in && !in.eof())
  {
    throw std::invalid_argument("Incorrect imput");
  }
  std::sort(vector.begin(), vector.end(), [](const tikhonov::DataStruct& lsh, const tikhonov::DataStruct& rsh)
    {
      if (lsh.key1 != rsh.key1)
      {
        return lsh.key1 < rsh.key1;
      }
      else if (lsh.key2 != rsh.key2)
      {
        return lsh.key2 < rsh.key2;
      }
      return lsh.str.size() < rsh.str.size();
    });
  std::copy(vector.begin(), vector.end(), std::ostream_iterator<DataStruct>(out, "\n"));
}
