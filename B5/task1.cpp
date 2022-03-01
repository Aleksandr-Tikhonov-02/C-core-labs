#include "task1.hpp"
#include <iostream>
#include <string>
#include <iterator>
#include <set>

void tikhonov::task1(std::istream& in, std::ostream& out)
{
  std::set<std::string> words{ std::istream_iterator<std::string>(in),
    std::istream_iterator<std::string>() };
  if (in.fail() && !in.eof()) 
  {
    throw std::runtime_error("Reading error");
  }
  std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(out, "\n"));
}
