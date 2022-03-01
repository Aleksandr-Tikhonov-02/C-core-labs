#include <iostream>
#include "task.hpp"

int main()
{
  try
  {
    tikhonov::task(std::cin, std::cout);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}
