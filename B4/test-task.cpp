#include <sstream>
#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "task.hpp"
#include "DataStruct.hpp"

BOOST_AUTO_TEST_SUITE(test_task)

  BOOST_AUTO_TEST_CASE(emptyInput)
  {
    std::istringstream in("");
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task(in, out));
    BOOST_CHECK_EQUAL(out.str(), "");
  }

  BOOST_AUTO_TEST_CASE(correct_imput)
  {
    std::istringstream in("3,   4,   aa\n3,4,   aaa\n-3,   1,a\n1,  -2,a\n");
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task(in, out));
    BOOST_CHECK_EQUAL(out.str(), "-3, 1, a\n1, -2, a\n3, 4, aa\n3, 4, aaa\n");
  }

  BOOST_AUTO_TEST_CASE(incorrect_imput)
  {
    std::istringstream in("1, fsfsd, dfs\n");
    std::ostringstream out;
    BOOST_CHECK_THROW(tikhonov::task(in, out), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(incorrect_key_value)
  {
    std::istringstream in("10, 2, a\n");
    std::ostringstream out;
    BOOST_CHECK_THROW(tikhonov::task(in, out), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
