#ifndef _PHONE_BOOK_
#define _PHONE_BOOK_

#include <list>
#include <string>

namespace tikhonov
{
  class PhoneBook
  {
  public:
    struct Record
    {
      std::string name;
      std::string phoneNumber;
    };

    enum class PlaceToInsert
    {
      BEFORE,
      AFTER
    };
    void pushBack(const Record& record);
    std::list<Record>::iterator insert(std::list<Record>::iterator i, const Record& record, const PlaceToInsert& place);
    std::list<Record>::iterator erase(std::list<Record>::iterator i);
    std::list<Record>::iterator getBegin();
    std::list<Record>::iterator getEnd();
    bool empty();
  private:
    std::list<Record> data_;
  };
}

#endif
