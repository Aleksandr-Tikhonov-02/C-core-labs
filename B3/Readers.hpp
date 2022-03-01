#ifndef _UTILS_
#define _UTILS_

#include <iosfwd>
#include <string>

namespace tikhonov
{
  struct MarkName
  {
    MarkName(std::string& str):
      str_(str)
    {}
    friend std::istream& operator>>(std::istream& in, const MarkName& markName);
  private:
    std::string& str_;
  };

  struct Number
  {
    Number(std::string& str):
      str_(str)
    {}
    friend std::istream& operator>>(std::istream& in, const Number& number);
  private:
    std::string& str_;
  };

  struct Name
  {
    Name(std::string& str):
      str_(str)
    {}
    friend std::istream& operator>>(std::istream& in, const Name& name);
  private:
    std::string& str_;
  };
  std::istream& operator>>(std::istream& in, const MarkName& markName);
  std::istream& operator>>(std::istream& in, const Number& number);
  std::istream& operator>>(std::istream& in, const Name& name);
}

#endif
