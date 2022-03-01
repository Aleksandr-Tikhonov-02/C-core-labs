#include "task1.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <map>
#include <stdexcept>
#include "Commands.hpp"
#include "BookMarks.hpp"

void tikhonov::task1(std::istream& in, std::ostream& out)
{
  tikhonov::BookMarks bookmarks;
  using MapOfCommands = std::map<std::string, void (*)(tikhonov::BookMarks&, std::istream&, std::ostream&)>;
  MapOfCommands commands =
  {
    {"add",    tikhonov::add},
    {"store",  tikhonov::store},
    {"insert", tikhonov::insertNote},
    {"delete", tikhonov::deleteNote},
    {"move",   tikhonov::move},
    {"show",   tikhonov::show}
  };
  while (in)
  {
    std::string command;
    in >> command;
    if (in.eof())
    {
      break;
    }
    MapOfCommands::const_iterator it = commands.find(command);
    if (it != commands.end())
    {
      it->second(bookmarks, in, out);
    }
    else
    {
      out << "<INVALID COMMAND>\n";
    }
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}
