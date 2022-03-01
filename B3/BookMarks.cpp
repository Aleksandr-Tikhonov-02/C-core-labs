#include "BookMarks.hpp"
#include <iostream>
#include "PhoneBook.hpp"
#include "BookMarkExceptions.hpp"

tikhonov::BookMarks::BookMarks()
{
  bookmarks_.insert(std::make_pair("current", book_.getBegin()));
}

void tikhonov::BookMarks::addNumber(const PhoneBook::Record& record)
{
  if (book_.empty())
  {
    book_.pushBack(record);
    bookmarks_.clear();
    bookmarks_.insert(std::make_pair("current", book_.getBegin()));
  }
  else
  {
    book_.pushBack(record);
  }
}

void tikhonov::BookMarks::storeBookMark(const std::string& oldMark, const std::string& newMark)
{
  if (book_.empty())
  {
    throw EmptyPhoneBook();
  }
  BookmarkIterator it = bookmarks_.find(oldMark);
  if (it == bookmarks_.end())
  {
    throw InvalidBookmark();
  }
  bookmarks_.insert(std::make_pair(newMark, it->second));
}

void tikhonov::BookMarks::insert(const PhoneBook::PlaceToInsert& place, const std::string& mark, const PhoneBook::Record& record)
{
  BookmarkIterator it = bookmarks_.find(mark);
  if (it == bookmarks_.end())
  {
    throw InvalidBookmark();
  }
  if (!book_.empty())
  {
    book_.insert(it->second, record, place);
  }
  else
  {
    book_.pushBack(record);
    bookmarks_.clear();
    bookmarks_.insert(std::make_pair("current", book_.getBegin()));
  }
}

void tikhonov::BookMarks::remove(const std::string& mark)
{
  if (book_.empty())
  {
    throw EmptyPhoneBook();
  }
  BookmarkIterator it = bookmarks_.find(mark);
  if (it == bookmarks_.end())
  {
    throw InvalidBookmark();
  }
  std::list<tikhonov::PhoneBook::Record>::iterator iterOld = it->second;
  std::list<tikhonov::PhoneBook::Record>::iterator iterNew = book_.erase(iterOld);
  if ((iterNew == book_.getEnd()) && !book_.empty())
  {
    iterNew--;
  }
  renewIter(iterOld, iterNew);
}

void tikhonov::BookMarks::getCurrent(const std::string& mark, std::ostream& out)
{
  BookmarkIterator it = bookmarks_.find(mark);
  if (it == bookmarks_.end())
  {
    throw tikhonov::InvalidBookmark();
  }
  if (book_.empty())
  {
    throw EmptyPhoneBook();
  }
  out << it->second->phoneNumber << ' ' << it->second->name << '\n';
}

void tikhonov::BookMarks::move(const std::string& mark, int steps)
{
  if (book_.empty())
  {
    throw EmptyPhoneBook();
  }
  BookmarkIterator it = bookmarks_.find(mark);
  if (it == bookmarks_.end())
  {
    throw tikhonov::InvalidBookmark();
  }
  while ((((it->second != --book_.getEnd()) && (steps > 0)) || ((it->second != book_.getBegin()) && (steps < 0))) && (steps != 0))
  {
    if (steps > 0)
    {
      ++it->second;
      steps--;
    }
    else
    {
      --it->second;
      steps++;
    }
  }
}

void tikhonov::BookMarks::move(const std::string& mark, const Step& step)
{
  if (book_.empty())
  {
    throw EmptyPhoneBook();
  }
  BookmarkIterator it = bookmarks_.find(mark);
  if (it == bookmarks_.end())
  {
    throw tikhonov::InvalidBookmark();
  }
  if (step == Step::FIRST)
  {
    it->second = book_.getBegin();
  }
  if (step == Step::LAST)
  {
    it->second = --book_.getEnd();
  }
}

void tikhonov::BookMarks::renewIter(const std::list<tikhonov::PhoneBook::Record>::iterator& oldIter,
  const std::list<tikhonov::PhoneBook::Record>::iterator& newIter)
{
  for (BookmarkIterator it = bookmarks_.begin(); it != bookmarks_.end(); ++it)
  {
    if (it->second == oldIter)
    {
      it->second = newIter;
    }
  }
}
