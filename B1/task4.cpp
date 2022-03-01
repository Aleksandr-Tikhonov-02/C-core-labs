#include "task4.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include "sort.hpp"
#include "sortTools.hpp"
#include "printContainer.hpp"
#include "direction.hpp"

void fillRandom(double* array, int size);

void tikhonov::task4(const char* directionstr, int size, std::ostream& out)
{
  Direction direction = getDirection(directionstr);
  if (size < 1)
  {
    throw std::invalid_argument("Incorrect array size");
  }
  std::unique_ptr<double[]> array = std::make_unique<double[]>(size);
  fillRandom(array.get(), size);
  std::vector<double> vector;
  for (int i = 0; i < size; ++i)
  {
    vector.push_back(array[i]);
    out << array[i] << " ";
  }
  out << '\n';
  tikhonov::sort<tikhonov::At, std::vector<double>>(vector, direction);
  tikhonov::print(vector.cbegin(), vector.cend(), out);
}

void fillRandom(double* array, int size)
{
  for (int i = 0; i < size; ++i)
  {
    array[i] = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;
  }
}
