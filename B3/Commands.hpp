#ifndef _COMMANDS_
#define _COMMANDS_

#include <iosfwd>
#include <functional>
#include "BookMarks.hpp"

namespace tikhonov
{
  void add(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out);
  void store(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out);
  void insertNote(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out);
  void deleteNote(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out);
  void move(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out);
  void show(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out);
}

#endif
