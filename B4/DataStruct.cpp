#include "DataStruct.hpp"
#include <iostream>
#include <cmath>
#include <cctype>
#include <boost/io/ios_state.hpp>

std::istream& tikhonov::skipSpaces(std::istream& in)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    boost::io::ios_flags_saver guard(in);
    char c;
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

std::istream& tikhonov::operator>>(std::istream& in, Delimeter&&)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    boost::io::ios_flags_saver guard(in);
    char c;
    in >> c;
    if (!in)
    {
      return in;
    }
    if (c != ',')
    {
      in.setstate(std::istream::failbit);
      return in;
    }
    in >> skipSpaces;
  }
  return in;
}

std::istream& tikhonov::operator>>(std::istream& in, DataStruct& dstruct)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    boost::io::ios_flags_saver guard(in);
    in >> std::noskipws;
    in >> dstruct.key1 >> Delimeter() >> dstruct.key2 >> Delimeter();
    if (!in)
    {
      return in;
    }
    if ((abs(dstruct.key1) > MAX_KEY_VALUE) || (abs(dstruct.key2) > MAX_KEY_VALUE))
    {
      in.setstate(std::istream::failbit);
      return in;
    }
    dstruct.str = "";
    char c;
    in >> c;
    while ((c != '\n') && !in.eof())
    {
      dstruct.str += c;
      in >> c;
    }
    if (dstruct.str.empty())
    {
      in.setstate(std::istream::failbit);
    }
  }
  return in;
}

std::ostream& tikhonov::operator<<(std::ostream& out, const DataStruct& dstruct)
{
  std::ostream::sentry sentry(out);
  if (sentry)
  {
    out << dstruct.key1 << ", " << dstruct.key2 << ", " << dstruct.str;
  }
  return out;
}
