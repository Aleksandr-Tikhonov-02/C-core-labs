#include "utils.hpp"
#include <iostream>
#include <boost/io/ios_state.hpp>

std::istream& tikhonov::operator>>(std::istream& in, Delimeter&& delim)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    boost::io::ios_flags_saver guard(in);
    in >> std::noskipws;
    char c = ' ';
    in >> c;
    if (!in) 
    {
      return in;
    }
    if (delim.delimeter_ != c) 
    {
      in.unget();
      in.setstate(std::istream::failbit);
    }
  }
  return in;
}

std::istream& tikhonov::skipSpaces(std::istream& in)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    char c = ' ';
    in >> c;
    while (!in.eof() && isblank(c))
    {
      in >> c;
    }
    if (!in.eof())
    {
      in.unget();
    }
  }
  return in;
}
