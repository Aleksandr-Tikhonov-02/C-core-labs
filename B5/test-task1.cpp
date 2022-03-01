#include <boost/test/unit_test.hpp>
#include <sstream>

#include "task1.hpp"

BOOST_AUTO_TEST_SUITE(testTask1)
BOOST_AUTO_TEST_CASE(test)
{
  std::istringstream in("Ivan hhh kkk kkk Ilya Ivan Gosha");
  std::ostringstream out;
  tikhonov::task1(in, out);
  BOOST_CHECK_EQUAL(out.str(), "Gosha\nIlya\nIvan\nhhh\nkkk\n");
}
BOOST_AUTO_TEST_SUITE_END()
