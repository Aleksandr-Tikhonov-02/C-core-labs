#include <iostream>
#include <stdexcept>
#include <boost/lexical_cast.hpp>
#include "task1.hpp"
#include "task2.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Incorrect number of arguments";
      return 1;
    }
    int taskNumber = boost::lexical_cast<int>(argv[1]);
    switch (taskNumber)
    {
    case 1:
      tikhonov::task1(std::cin, std::cout);
      break;
    case 2:
      tikhonov::task2(std::cout);
      break;
    default:
      std::cerr << "You can enter 1 or 2 as task";
      return 1;
    }
  }
  catch (const boost::bad_lexical_cast& e)
  {
    std::cerr << "Incorrect imput, expected task number";
    return 1;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }
  return 0;
}
