#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <sstream>
#include "task4.hpp"
#include "direction.hpp"

BOOST_AUTO_TEST_SUITE(task4)

  BOOST_AUTO_TEST_CASE(incorrectDirection)
  {
    std::ostringstream out;
    BOOST_CHECK_THROW(tikhonov::task4("dfgdfgdfg", 5, out), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(incorrectSize)
  {
    std::ostringstream out;
    BOOST_CHECK_THROW(tikhonov::task4("ascending", 0, out), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(correctAscendingSort)
  {
    std::stringstream out;
    srand(0);
    BOOST_CHECK_NO_THROW(tikhonov::task4("ascending", 4, out));
    std::vector<double> vectorFromTask;
    double number = 0;
    for (int i = 0; i < 4; ++i)
    {
      out >> number;
      BOOST_CHECK_EQUAL(out.good() || out.eof(), true);
      BOOST_TEST(number <= 1.0);
      BOOST_TEST(number >= -1.0);
      vectorFromTask.push_back(number);
    }
    std::vector<double> vectorSortedFromTask;
    number = 0;
    for (int i = 0; i < 4; ++i)
    {
      out >> number;
      BOOST_CHECK_EQUAL(out.good() || out.eof(), true);
      BOOST_TEST(number <= 1.0);
      BOOST_TEST(number >= -1.0);
      vectorSortedFromTask.push_back(number);
    }
    std::vector<double> vectorSorted(vectorFromTask);
    std::sort(vectorSorted.begin(), vectorSorted.end());
    BOOST_CHECK_EQUAL_COLLECTIONS(vectorSortedFromTask.begin(), vectorSortedFromTask.end(), vectorSorted.begin(), vectorSorted.end());
  }

  BOOST_AUTO_TEST_CASE(correctDescendingSort)
  {
    std::stringstream out;
    srand(0);
    BOOST_CHECK_NO_THROW(tikhonov::task4("descending", 4, out));
    std::vector<double> vectorFromTask;
    double number = 0;
    for (int i = 0; i < 4; ++i)
    {
      out >> number;
      BOOST_CHECK_EQUAL(out.good() || out.eof(), true);
      BOOST_TEST(number <= 1.0);
      BOOST_TEST(number >= -1.0);
      vectorFromTask.push_back(number);
    }
    std::vector<double> vectorSortedFromTask;
    number = 0;
    for (int i = 0; i < 4; ++i)
    {
      out >> number;
      BOOST_CHECK_EQUAL(out.good() || out.eof(), true);
      BOOST_TEST(number <= 1.0);
      BOOST_TEST(number >= -1.0);
      vectorSortedFromTask.push_back(number);
    }
    std::vector<double> vectorSorted(vectorFromTask);
    std::sort(vectorSorted.begin(), vectorSorted.end(), std::greater<>());
    BOOST_CHECK_EQUAL_COLLECTIONS(vectorSortedFromTask.begin(), vectorSortedFromTask.end(), vectorSorted.begin(), vectorSorted.end());
  }

BOOST_AUTO_TEST_SUITE_END()
