#include <boost/test/unit_test.hpp>
#include <sstream>
#include <stdexcept>
#include "task1.hpp"
#include "direction.hpp"

BOOST_AUTO_TEST_SUITE(task1)

  BOOST_AUTO_TEST_CASE(incorrectNameOfDirection)
  {
    std::istringstream in("1 2 3 4\n");
    std::ostringstream out;
    BOOST_CHECK_THROW(tikhonov::task1("nothing", in, out), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(incorrectDataBuffer)
  {
    std::istringstream in("1 2 e 4\n");
    std::ostringstream out;
    BOOST_CHECK_THROW(tikhonov::task1("ascending", in, out), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(correctAscendingSort)
  {
    std::istringstream in("2 4 3 1\n");
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task1("ascending", in, out));
    BOOST_CHECK_EQUAL(out.str(), "1 2 3 4\n1 2 3 4\n1 2 3 4\n");
  }

  BOOST_AUTO_TEST_CASE(correctDescendingSort)
  {
    std::istringstream in("1 3 4 2\n");
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task1("descending", in, out));
    BOOST_CHECK_EQUAL(out.str(), "4 3 2 1\n4 3 2 1\n4 3 2 1\n");
  }

BOOST_AUTO_TEST_SUITE_END()
