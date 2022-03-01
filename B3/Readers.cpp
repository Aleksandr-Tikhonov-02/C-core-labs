#include "Readers.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <boost/io/ios_state.hpp>
#include "BookMarkExceptions.hpp"

std::istream& tikhonov::operator>>(std::istream& in, const MarkName& markName)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    std::string str;
    char c = '0';
    boost::io::ios_flags_saver guard(in);
    in >> c >> std::noskipws;
    while (in)
    {
      if (in.eof() || (c == '\n') || (c == ' '))
      {
        if (!str.empty())
        {
          in.unget();
        }
        markName.str_ = str;
        return in;
      }
      if (std::isalnum(c) || (c == '-'))
      {
        str += c;
        in >> c;
      }
      else
      {
        in.setstate(std::istream::failbit);
        return in;
      }
    }
  }
  return in;
}

std::istream& tikhonov::operator>>(std::istream& in, const Number& number)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    std::string str;
    char c = '0';
    boost::io::ios_flags_saver guard(in);
    in >> c >> std::noskipws;
    while (in)
    {
      if (in.eof() || (c == '\n') || (c == ' '))
      {
        if (!str.empty())
        {
          in.unget();
        }
        number.str_ = str;
        return in;
      }
      if (std::isdigit(c))
      {
        str += c;
        in >> c;
      }
      else
      {
        in.setstate(std::istream::failbit);
        return in;
      }
    }
  }
  return in;
}

std::istream& tikhonov::operator>>(std::istream& in, const Name& name)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    boost::io::ios_flags_saver guard(in);
    std::string str;
    char c = ' ';
    in >> c;
    in.unget();
    if (c != '\"')
    {
      in.setstate(std::istream::failbit);
      return in;
    }
    std::getline(in, str, '\n');
    if (str.back() != '\"')
    {
      in.setstate(std::istream::failbit);
      return in;
    }
    std::stringstream tmp(str);
    tmp >> std::quoted(str);
    name.str_ = str;
    in.unget();
  }
  return in;
}
