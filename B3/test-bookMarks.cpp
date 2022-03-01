#include <boost/test/unit_test.hpp>
#include <sstream>
#include "BookMarks.hpp"
#include "BookMarkExceptions.hpp"

BOOST_AUTO_TEST_SUITE(test_bookMarks)


  BOOST_AUTO_TEST_CASE(test_constructor)
  {
    BOOST_CHECK_NO_THROW(tikhonov::BookMarks bookMarkstmp);
    tikhonov::BookMarks bookMark;
    std::ostringstream out;
    BOOST_CHECK_THROW(bookMark.getCurrent("current", out), tikhonov::EmptyPhoneBook);
  }

  BOOST_AUTO_TEST_CASE(test_addNumber)
  {
    tikhonov::BookMarks bookMark;
    std::ostringstream out;
    bookMark.addNumber({ "Aleksandr", "666666" });
    bookMark.getCurrent("current", out);
    BOOST_CHECK_EQUAL(out.str(), "666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(test_storeBookMark)
  {
    tikhonov::BookMarks bookMark;
    std::ostringstream out;
    bookMark.addNumber({ "Aleksandr", "666666" });
    bookMark.storeBookMark("current", "firstRecord");
    bookMark.getCurrent("firstRecord", out);
    BOOST_CHECK_EQUAL(out.str(), "666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(test_insert)
  {
    tikhonov::BookMarks bookMark;
    std::ostringstream out;
    bookMark.addNumber({ "Aleksandr", "666666" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Boris", "777777" });
    bookMark.move("current", 1);
    bookMark.getCurrent("current", out);
    BOOST_CHECK_EQUAL(out.str(), "777777 Boris\n");
  }

  BOOST_AUTO_TEST_CASE(test_remove)
  {
    tikhonov::BookMarks bookMark;
    std::ostringstream out;
    bookMark.addNumber({ "Aleksandr", "666666" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Boris", "777777" });
    bookMark.remove("current");
    bookMark.getCurrent("current", out);
    BOOST_CHECK_EQUAL(out.str(), "777777 Boris\n");
  }

  BOOST_AUTO_TEST_CASE(test_move_to_last)
  {
    tikhonov::BookMarks bookMark;
    std::ostringstream out;
    bookMark.addNumber({ "Aleksandr", "666666" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Boris", "777777" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Aleksey", "666777" });
    bookMark.move("current", tikhonov::BookMarks::Step::LAST);
    bookMark.getCurrent("current", out);
    BOOST_CHECK_EQUAL(out.str(), "777777 Boris\n");
  }

  BOOST_AUTO_TEST_CASE(test_move_to_first)
  {
    tikhonov::BookMarks bookMark;
    std::ostringstream out;
    bookMark.addNumber({ "Aleksandr", "666666" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Boris", "777777" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Aleksey", "666777" });
    bookMark.move("current", tikhonov::BookMarks::Step::FIRST);
    bookMark.getCurrent("current", out);
    BOOST_CHECK_EQUAL(out.str(), "666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(test_move_by_positive_step_not_out_of_range)
  {
    tikhonov::BookMarks bookMark;
    std::ostringstream out;
    bookMark.addNumber({ "Aleksandr", "666666" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Boris", "777777" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Aleksey", "666777" });
    bookMark.move("current", 2);
    bookMark.getCurrent("current", out);
    BOOST_CHECK_EQUAL(out.str(), "777777 Boris\n");
  }

  BOOST_AUTO_TEST_CASE(test_move_by_negative_step_not_out_of_range)
  {
    tikhonov::BookMarks bookMark;
    std::ostringstream out1;
    std::ostringstream out2;
    std::ostringstream out3;
    bookMark.addNumber({ "Aleksandr", "666666" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Boris", "777777" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Aleksey", "666777" });
    bookMark.move("current", 2);
    bookMark.getCurrent("current", out1);
    BOOST_CHECK_EQUAL(out1.str(), "777777 Boris\n");
    bookMark.move("current", -1);
    bookMark.getCurrent("current", out2);
  }

  BOOST_AUTO_TEST_CASE(test_move_with_step_out_of_range)
  {
    tikhonov::BookMarks bookMark;
    std::ostringstream out1;
    std::ostringstream out2;
    bookMark.addNumber({ "Aleksandr", "666666" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Boris", "777777" });
    bookMark.insert(tikhonov::PhoneBook::PlaceToInsert::AFTER, "current", { "Aleksey", "666777" });
    bookMark.move("current", 10);
    bookMark.getCurrent("current", out1);
    BOOST_CHECK_EQUAL(out1.str(), "777777 Boris\n");
    bookMark.move("current", -10);
    bookMark.getCurrent("current", out2);
    BOOST_CHECK_EQUAL(out2.str(), "666666 Aleksandr\n");
  }

BOOST_AUTO_TEST_SUITE_END()
