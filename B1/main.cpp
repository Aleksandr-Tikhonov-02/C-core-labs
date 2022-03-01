#include <iostream>
#include <sstream>
#include <stdexcept>
#include "task1.hpp"
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"
#include "stringConversion.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc < 2)
    {
      std::cerr << "It must be more than 1 argument\n";
      return 1;
    }
    int taskNumber = tikhonov::stringConversion<int>(argv[1]);
    switch (taskNumber)
    {
    case 1:
      if (argc < 3)
      {
        std::cerr << "You should have 3 arguments to start this task: direction is not found\n";
        return 1;
      }
      tikhonov::task1(argv[2], std::cin, std::cout);
      break;
    case 2:
      if (argc < 3)
      {
        std::cerr << "You should have 3 arguments to start this task: file name isn't found\n";
        return 1;
      }
      tikhonov::task2(argv[2], std::cout);
      break;
    case 3:
      tikhonov::task3(std::cin, std::cout);
      break;
    case 4:
    {
      if (argc < 4)
      {
        std::cerr << "You should have 4 arguments: direction or size aren't found\n";
        return 1;
      }
      int vectorSize = tikhonov::stringConversion<int>(argv[3]);
      srand(time(0));
      tikhonov::task4(argv[2], vectorSize, std::cout);
      break;
    }
    default:
      std::cerr << "You can enter 1, 2, 3 or 4 as task number\n";
      return 1;
    }
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
