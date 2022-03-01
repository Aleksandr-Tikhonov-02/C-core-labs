#include <boost/test/unit_test.hpp>
#include "task1.hpp"
#include "BookMarks.hpp"
#include "BookMarkExceptions.hpp"

BOOST_AUTO_TEST_SUITE(test_Commands)

  BOOST_AUTO_TEST_CASE(empty_list_show_current)
  {
    std::istringstream in("show current ");
    std::ostringstream out;
    tikhonov::task1(in, out);
    BOOST_CHECK_EQUAL(out.str(), "<EMPTY>\n");
  }

  BOOST_AUTO_TEST_CASE(invalid_command)
  {
    std::istringstream in("asdjfl dff");
    std::ostringstream out;
    tikhonov::task1(in, out);
    BOOST_CHECK_EQUAL(out.str(), "<INVALID COMMAND>\n");
  }

  BOOST_AUTO_TEST_CASE(show_invalid_bookmark)
  {
    std::istringstream in("show incorBookMark ");
    std::ostringstream out;
    tikhonov::task1(in, out);
    BOOST_CHECK_EQUAL(out.str(), "<INVALID BOOKMARK>\n");
  }

  BOOST_AUTO_TEST_CASE(adding_invalid_note)
  {
    std::istringstream in("add 666666 \"Aleksandr ");
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task1(in, out));
    BOOST_CHECK_EQUAL(out.str(), "<INVALID COMMAND>\n");
  }

  BOOST_AUTO_TEST_CASE(adding_note)
  {
    std::istringstream in("add 666666 \"Aleksandr\"\nshow current\n");
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task1(in, out));
    BOOST_CHECK_EQUAL(out.str(), "666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(adding_invalid_note2)
  {
    std::istringstream in("add 666666 Aleksandr");
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task1 (in, out));
    BOOST_CHECK_EQUAL(out.str(), "<INVALID COMMAND>\n");
  }

  BOOST_AUTO_TEST_CASE(show_added_note)
  {
    std::istringstream in("add 666666 \"Aleksandr\"\nshow current ");
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task1(in, out));
    BOOST_CHECK_EQUAL(out.str(), "666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(move_to_last)
  {
    std::istringstream input("add 666666 \"Aleksandr\"\n add 777777 \"Boris\"\nmove current last\nshow current ");
    std::ostringstream output;
    tikhonov::task1(input, output);
    BOOST_CHECK_EQUAL(output.str(), "777777 Boris\n");
  }

  BOOST_AUTO_TEST_CASE(move_to_first)
  {
    std::istringstream input(
      "add 666666 \"Aleksandr\"\n add 777777 \"Boris\"\nmove current last\nshow current\nmove current first\nshow current\n ");
    std::ostringstream output;
    tikhonov::task1(input, output);
    BOOST_CHECK_EQUAL(output.str(), "777777 Boris\n666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(move_steps)
  {
    std::istringstream input(
      "add 666666 \"Aleksandr\"\n add 777777 \"Boris\"\nmove current 1\n show current\nmove current -1\nshow current ");
    std::ostringstream output;
    tikhonov::task1(input, output);
    BOOST_CHECK_EQUAL(output.str(), "777777 Boris\n666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(store)
  {
    std::istringstream input("add 666666 \"Aleksandr\"\nstore current newMark\n show newMark ");
    std::ostringstream output;
    tikhonov::task1(input, output);
    BOOST_CHECK_EQUAL(output.str(), "666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(insert_before)
  {
    std::istringstream in("insert before current 666666 \"Aleksandr\"\nmove current -1\nshow current\n ");
    std::ostringstream out;
    tikhonov::task1(in, out);
    BOOST_CHECK_EQUAL(out.str(), "666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(insert_after)
  {
    std::istringstream input("insert after current 666666 \"Aleksandr\"\n show current\n ");
    std::ostringstream output;
    tikhonov::task1(input, output);
    BOOST_CHECK_EQUAL(output.str(), "666666 Aleksandr\n");
  }

  BOOST_AUTO_TEST_CASE(deleting)
  {
    std::istringstream input(
      "add 666666 \"Aleksandr\"\n"
      "add 666777 \"Aleksey\"\n"
      "add 777777 \"Boris\"\n"
      "store current record1\n"
      "delete record1\n"
      "show record1\n ");
    std::ostringstream output;
    tikhonov::task1(input, output);
    BOOST_CHECK_EQUAL(output.str(), "666777 Aleksey\n");
  }

BOOST_AUTO_TEST_SUITE_END()
