#include "task2.hpp"
#include <iostream>
#include <algorithm>
#include "FactorialContainer.hpp"

void tikhonov::task2(std::ostream& out)
{
  FactorialContainer container;

  std::copy(container.cbegin(), container.cend(), std::ostream_iterator<unsigned int>(out, " "));
  out << '\n';

  std::reverse_copy(container.cbegin(), container.cend(), std::ostream_iterator<unsigned int>(out, " "));
  out << '\n';
}
