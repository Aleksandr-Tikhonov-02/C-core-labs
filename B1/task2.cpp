#include "task2.hpp"
#include <utility>
#include <fstream>
#include <vector>
#include <memory>
#include "printContainer.hpp"

void tikhonov::task2(const char* fName, std::ostream& out)
{
  std::ifstream file(fName);
  if (!file.is_open())
  {
    throw std::runtime_error("Incorrect file");
  }
  std::streamsize bufferSize = 1024;
  const int BUFFERCOEF = 2;
  std::streamsize length = 0;
  std::unique_ptr<char[], void(*)(void*)> arr(static_cast<char*>(malloc(bufferSize * sizeof(char))), std::free);
  while (file)
  {
    file.read(arr.get() + length, bufferSize);
    length += file.gcount();
    if (file.eof())
    {
      break;
    }
    if (!file)
    {
      file.close();
      throw std::runtime_error("Reading file error");
    }
    std::unique_ptr<char[], void(*)(void*)> tmp(static_cast<char*>(realloc(arr.release(),
      ((bufferSize * BUFFERCOEF) + length) * sizeof(char))), std::free);
    bufferSize *= BUFFERCOEF;
    std::swap(arr, tmp);
  }
  file.close();
  std::vector<char> vector(arr.get(), arr.get() + length);
  if (!vector.empty())
  {
    out.write(&vector[0], vector.size());
  }
}
