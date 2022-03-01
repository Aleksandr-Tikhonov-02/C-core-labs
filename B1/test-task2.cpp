#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include "task2.hpp"

BOOST_AUTO_TEST_SUITE(task2)

  BOOST_AUTO_TEST_CASE(incorrectFileName)
  {
    std::ostringstream out;
    BOOST_CHECK_THROW(tikhonov::task2("12345", out), std::runtime_error);
  }

  BOOST_AUTO_TEST_CASE(correctFile)
  {
    std::ofstream file("data.txt");
    std::string str("something .... data");
    file << str;
    file.close();
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task2("data.txt", out));
    BOOST_CHECK_EQUAL(out.str(), str);
  }

  BOOST_AUTO_TEST_CASE(correctFile2)
  {
    std::ofstream file("data2.txt");
    file.close();
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(tikhonov::task2("data2.txt", out));
    BOOST_CHECK_EQUAL(out.str(), "");
  }

BOOST_AUTO_TEST_SUITE_END()
