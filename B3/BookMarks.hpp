#ifndef _BOOKMARKS_
#define _BOOKMARKS_

#include <list>
#include <string>
#include <map>
#include "PhoneBook.hpp"

namespace tikhonov
{
  class BookMarks
  {
  public:
    enum class Step
    {
      FIRST,
      LAST
    };
    BookMarks();
    void addNumber(const PhoneBook::Record& record);
    void storeBookMark(const std::string& oldMark, const std::string& newMark);
    void insert(const PhoneBook::PlaceToInsert& place, const std::string& mark, const PhoneBook::Record& record);
    void remove(const std::string& mark);
    void getCurrent(const std::string& mark, std::ostream& out);
    void move(const std::string& mark, int steps);
    void move(const std::string& mark, const Step& step);

  private:
    using BookmarkIterator = std::map<std::string, std::list<tikhonov::PhoneBook::Record>::iterator>::iterator;
    tikhonov::PhoneBook book_;
    std::map<std::string, std::list<tikhonov::PhoneBook::Record>::iterator> bookmarks_;
    void renewIter(const std::list<tikhonov::PhoneBook::Record>::iterator& oldIter,
      const std::list<tikhonov::PhoneBook::Record>::iterator& newIter);
  };
}

#endif
