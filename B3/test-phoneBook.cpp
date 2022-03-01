#include <boost/test/unit_test.hpp>
#include "PhoneBook.hpp"

BOOST_AUTO_TEST_SUITE(test_phone_book)

  tikhonov::PhoneBook book;
  tikhonov::PhoneBook::Record record1{ "Aleksandr", "79232346593" };
  tikhonov::PhoneBook::Record record2{ "Sergey", "89334353675" };
  tikhonov::PhoneBook::Record record3{ "Boris", "89114332567" };
  tikhonov::PhoneBook::Record record4{ "Ivan", "72984569865" };

  BOOST_AUTO_TEST_CASE(test_constructor)
  {
    BOOST_CHECK_NO_THROW(tikhonov::PhoneBook tmp);
  }

  BOOST_AUTO_TEST_CASE(test_pushBack_method)
  {
    BOOST_CHECK_NO_THROW(book.pushBack(record1));
    BOOST_CHECK_NO_THROW(book.pushBack(record3));
    std::list<tikhonov::PhoneBook::Record>::iterator it = book.getBegin();
    BOOST_CHECK_EQUAL(it->name, record1.name);
    BOOST_CHECK_EQUAL((it++)->phoneNumber, record1.phoneNumber);
    BOOST_CHECK_EQUAL(it->name, record3.name);
    BOOST_CHECK_EQUAL((it++)->phoneNumber, record3.phoneNumber);
  }

  BOOST_AUTO_TEST_CASE(test_insert_method)
  {
    std::list<tikhonov::PhoneBook::Record>::iterator it = book.getBegin();
    it++;
    book.insert(it, record4, tikhonov::PhoneBook::PlaceToInsert::AFTER);
    book.insert(it, record2, tikhonov::PhoneBook::PlaceToInsert::BEFORE);
    it = book.getBegin();
    BOOST_CHECK_EQUAL(it->name, record1.name);
    BOOST_CHECK_EQUAL((it++)->phoneNumber, record1.phoneNumber);
    BOOST_CHECK_EQUAL(it->name, record2.name);
    BOOST_CHECK_EQUAL((it++)->phoneNumber, record2.phoneNumber);
    BOOST_CHECK_EQUAL(it->name, record3.name);
    BOOST_CHECK_EQUAL((it++)->phoneNumber, record3.phoneNumber);
    BOOST_CHECK_EQUAL(it->name, record4.name);
    BOOST_CHECK_EQUAL((it++)->phoneNumber, record4.phoneNumber);
  }

  BOOST_AUTO_TEST_CASE(test_erase_method)
  {
    std::list<tikhonov::PhoneBook::Record>::iterator it = book.getBegin();
    it++;
    std::list<tikhonov::PhoneBook::Record>::iterator itTmp = book.erase(it);
    BOOST_CHECK_EQUAL(itTmp->name, record3.name);
    BOOST_CHECK_EQUAL(itTmp->phoneNumber, record3.phoneNumber);
    it = book.getBegin();
    BOOST_CHECK_EQUAL(it->name, record1.name);
    BOOST_CHECK_EQUAL((it++)->phoneNumber, record1.phoneNumber);
    BOOST_CHECK_EQUAL(it->name, record3.name);
    BOOST_CHECK_EQUAL((it++)->phoneNumber, record3.phoneNumber);
    BOOST_CHECK_EQUAL(it->name, record4.name);
    BOOST_CHECK_EQUAL((it++)->phoneNumber, record4.phoneNumber);
  }

  BOOST_AUTO_TEST_CASE(test_getBegin_getEnd_methods)
  {
    std::list<tikhonov::PhoneBook::Record>::iterator it = book.getBegin();
    BOOST_CHECK_EQUAL(it->name, record1.name);
    BOOST_CHECK_EQUAL(it->phoneNumber, record1.phoneNumber);
    it = book.getEnd();
    it--;
    BOOST_CHECK_EQUAL(it->name, record4.name);
    BOOST_CHECK_EQUAL(it->phoneNumber, record4.phoneNumber);

  }

  BOOST_AUTO_TEST_CASE(test_empty_method)
  {
    tikhonov::PhoneBook tmp;
    BOOST_CHECK_EQUAL(tmp.empty(), true);
    tmp.pushBack(record1);
    BOOST_CHECK_EQUAL(tmp.empty(), false);
  }

BOOST_AUTO_TEST_SUITE_END()
