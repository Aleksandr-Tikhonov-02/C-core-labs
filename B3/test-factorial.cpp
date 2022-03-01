#include <boost/test/unit_test.hpp>
#include <sstream>
#include "FactorialContainer.hpp"
#include "task2.hpp"

BOOST_AUTO_TEST_SUITE(factorial)

  BOOST_AUTO_TEST_CASE(task_2)
  {
    std::ostringstream out;
    tikhonov::task2(out);
    BOOST_CHECK_EQUAL(out.str(), "1 2 6 24 120 720 5040 40320 362880 3628800 \n3628800 362880 40320 5040 720 120 24 6 2 1 \n");
  }

  BOOST_AUTO_TEST_CASE(test_with_const_iterator)
  {
    std::ostringstream out;
    tikhonov::FactorialContainer container;
    tikhonov::FactorialContainer::const_iterator it = container.cbegin();
    while (it != container.cend())
    {
      out << *it << ' ';
      ++it;
    }
    BOOST_CHECK_EQUAL(out.str(), "1 2 6 24 120 720 5040 40320 362880 3628800 ");
  }

  BOOST_AUTO_TEST_CASE(test_with_const_reverse_iterator)
  {
    std::ostringstream out;
    tikhonov::FactorialContainer container;
    tikhonov::FactorialContainer::const_reverse_iterator reverseIt = container.crbegin();
    while (reverseIt != container.crend())
    {
      out << *reverseIt << ' ';
      ++reverseIt;
    }
    BOOST_CHECK_EQUAL(out.str(), "3628800 362880 40320 5040 720 120 24 6 2 1 ");
  }

BOOST_AUTO_TEST_SUITE_END()
