#include "Commands.hpp"
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "Readers.hpp"
#include "BookMarkExceptions.hpp"
#include "PhoneBook.hpp"

void tikhonov::add(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out)
{
  try
  {
    std::string number;
    std::string name;
    in >> Number(number) >> Name(name);
    if (in.fail())
    {
      in.clear();
      throw tikhonov::InvalidCommand();
    }
    bookmarks.addNumber({name, number});
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}

void tikhonov::store(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out)
{
  try
  {
    std::string markName, newMarkName;
    in >> MarkName(markName) >> MarkName(newMarkName);
    if (in.fail())
    {
      in.clear();
      throw tikhonov::InvalidCommand();
    }
    bookmarks.storeBookMark(markName, newMarkName);
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}

void tikhonov::insertNote(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out)
{
  try
  {
    std::string place;
    in >> place;
    if (in.fail())
    {
      in.clear();
      throw tikhonov::InvalidCommand();
    }
    std::string markName, number,name;
    in >> MarkName(markName) >> Number(number) >> Name(name);
    if (!in && !in.eof())
    {
      in.clear();
      throw tikhonov::InvalidCommand();
    }
    if (place == "before")
    {
      bookmarks.insert(tikhonov::PhoneBook::PlaceToInsert::BEFORE, markName, {name, number});
    }
    else if (place == "after")
    {
      bookmarks.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, markName, {name, number});
    }
    else
    {
      throw tikhonov::InvalidCommand();
    }
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}

void tikhonov::deleteNote(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out)
{
  try
  {
    std::string markName;
    in >> MarkName(markName);
    if (in.fail())
    {
      in.clear();
      throw tikhonov::InvalidCommand();
    }
    bookmarks.remove(markName);
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}

void tikhonov::move(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out)
{
  try
  {
    std::string markName;
    in >> MarkName(markName);
    if (in.fail())
    {
      in.clear();
      throw tikhonov::InvalidCommand();
    }
    std::string step;
    in >> step;
    if (step == "first")
    {
      bookmarks.move(markName, tikhonov::BookMarks::Step::FIRST);
    }
    else if (step == "last")
    {
      bookmarks.move(markName, tikhonov::BookMarks::Step::LAST);
    }
    else
    {
      int steps = 0;
      try
      {
        steps = boost::lexical_cast<int>(step);
      }
      catch (const boost::bad_lexical_cast& e)
      {
        throw tikhonov::InvalidStep();
      }
      bookmarks.move(markName, steps);
    }
  }
  catch (const std::exception& exception)
  {
    out << exception.what() << '\n';
  }
}

void tikhonov::show(tikhonov::BookMarks& bookmarks, std::istream& in, std::ostream& out)
{
  try
  {
    std::string markName;
    in >> MarkName(markName);
    if (in.fail())
    {
      in.clear();
      throw tikhonov::InvalidCommand();
    }
    bookmarks.getCurrent(markName, out);
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}
