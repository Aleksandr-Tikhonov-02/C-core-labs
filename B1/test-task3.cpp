#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <sstream>
#include "task3.hpp"

BOOST_AUTO_TEST_SUITE(task3)

  BOOST_AUTO_TEST_SUITE(input)

    BOOST_AUTO_TEST_CASE(incorrectImput1)
    {
      std::istringstream in("1 2 3 b 4\n");
      std::ostringstream out;
      BOOST_CHECK_THROW(tikhonov::task3(in, out), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(incorrectImput3)
    {
      std::istringstream in("1 2 3 4 5\n");
      std::ostringstream out;
      BOOST_CHECK_THROW(tikhonov::task3(in, out), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(correctImput1)
    {
      std::istringstream in("");
      std::ostringstream out;
      BOOST_CHECK_NO_THROW(tikhonov::task3(in, out));
    }

    BOOST_AUTO_TEST_CASE(correctImput2)
    {
      std::istringstream in("0\n");
      std::ostringstream out;
      BOOST_CHECK_NO_THROW(tikhonov::task3(in, out));
    }

    BOOST_AUTO_TEST_CASE(correctImput3)
    {
      std::istringstream in("1 2 3 4 5 0\n");
      std::ostringstream out;
      BOOST_CHECK_NO_THROW(tikhonov::task3(in, out));
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(mainTask)


    BOOST_AUTO_TEST_CASE(onlyOddNumbers_last1)
    {
      std::istringstream in("3 11 5 1 0\n");
      std::ostringstream out;
      tikhonov::task3(in, out);
      BOOST_CHECK_EQUAL(out.str(), "3 11 5 1\n");
    }

    BOOST_AUTO_TEST_CASE(onlyEvenNumbers_last1)
    {
      std::istringstream in("2 4 6 8 10 1 0\n");
      std::ostringstream out;
      tikhonov::task3(in, out);
      BOOST_CHECK_EQUAL(out.str(), "1\n");
    }

    BOOST_AUTO_TEST_CASE(differentNumbers_last1)
    {
      std::istringstream in("1 2 3 4 5 6 7 8 9 10 1 0\n");
      std::ostringstream out;
      tikhonov::task3(in, out);
      BOOST_CHECK_EQUAL(out.str(), "1 3 5 7 9 1\n");
    }

    BOOST_AUTO_TEST_CASE(numbersThatNotDividedByThree_last2)
    {
      std::istringstream in("1 2 4 5 7 8 2 0\n");
      std::ostringstream out;
      tikhonov::task3(in, out);
      BOOST_CHECK_EQUAL(out.str(), "1 2 4 5 7 8 2\n");
    }

    BOOST_AUTO_TEST_CASE(allNumbersDividedByThree_last2)
    {
      std::istringstream in("3 6 9 33 2 0\n");
      std::ostringstream out;
      tikhonov::task3(in, out);
      BOOST_CHECK_EQUAL(out.str(), "3 1 1 1 6 1 1 1 9 1 1 1 33 1 1 1 2\n");
    }

    BOOST_AUTO_TEST_CASE(differentNumbers_last2)
    {
      std::istringstream in("1 2 3 4 5 2 0\n");
      std::ostringstream out;
      tikhonov::task3(in, out);
      BOOST_CHECK_EQUAL(out.str(), "1 2 3 1 1 1 4 5 2\n");
    }

    BOOST_AUTO_TEST_CASE(correctDataButLastIsNot1or2)
    {
      std::istringstream in("1 2 3 4 5 7 0\n");
      std::ostringstream out;
      tikhonov::task3(in, out);
      BOOST_CHECK_EQUAL(out.str(), "1 2 3 4 5 7\n");
    }

  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
