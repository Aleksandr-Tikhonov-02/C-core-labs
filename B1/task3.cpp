#include "task3.hpp"
#include <iostream>
#include <vector>
#include "printContainer.hpp"

void tikhonov::task3(std::istream& in, std::ostream& out)
{
  std::vector<int> vector;
  bool firstIteration = true;
  while (in)
  {
    int element = 0;
    in >> element;
    if (in.eof())
    {
      if (firstIteration)
      {
        break;
      }
      throw std::invalid_argument("Input must end with zero");
    }
    if (in.fail())
    {
      throw std::invalid_argument("Incorrect data");
    }
    if (element == 0)
    {
      break;
    }
    vector.push_back(element);
    firstIteration = false;
  }
  if (vector.empty())
  {
    return;
  }
  if (*(vector.end() - 1) == 1)
  {
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end();)
    {
      if (*it % 2 == 0)
      {
        it = vector.erase(it);
      }
      else
      {
        it++;
      }
    }
  }
  if (*(vector.end() - 1) == 2)
  {
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
    {
      if (*it % 3 == 0)
      {
        it = vector.insert(++it, 3, 1);
        it += 2;
      }
    }
  }
  tikhonov::print(vector.cbegin(), vector.cend(), out);
}
