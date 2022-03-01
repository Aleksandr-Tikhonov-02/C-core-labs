#include "PhoneBook.hpp"
#include <stdexcept>

void tikhonov::PhoneBook::pushBack(const Record& record)
{
  data_.push_back(record);
}

std::list<tikhonov::PhoneBook::Record>::iterator tikhonov::PhoneBook::insert(std::list<Record>::iterator i,
  const Record& record, const PlaceToInsert& place)
{
  if (data_.empty())
  {
    pushBack(record);
    return getBegin();
  }
  if (place == PhoneBook::PlaceToInsert::AFTER)
  {
    i++;
  }
  return data_.insert(i, record);
}

std::list<tikhonov::PhoneBook::Record>::iterator tikhonov::PhoneBook::erase(std::list<Record>::iterator i)
{
  return data_.erase(i);
}

std::list<tikhonov::PhoneBook::Record>::iterator tikhonov::PhoneBook::getBegin()
{
  return data_.begin();
}

std::list<tikhonov::PhoneBook::Record>::iterator tikhonov::PhoneBook::getEnd()
{
  return data_.end();
}

bool tikhonov::PhoneBook::empty()
{
  return data_.empty();
}
