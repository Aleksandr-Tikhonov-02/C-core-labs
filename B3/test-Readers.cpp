#include <boost/test/unit_test.hpp>
#include <sstream>
#include <string>
#include "Readers.hpp"

BOOST_AUTO_TEST_SUITE(test_readers)

  BOOST_AUTO_TEST_CASE(test_markName)
  {
    std::string mark1;
    std::string mark2;
    std::string mark3;
    std::istringstream in1("mark-Name\n");
    std::istringstream in2("mark.Name\n");
    std::istringstream in3("0df0-fgh\n");
    in1 >> tikhonov::MarkName(mark1);
    in2 >> tikhonov::MarkName(mark2);
    in3 >> tikhonov::MarkName(mark3);
    BOOST_CHECK_EQUAL(mark1, "mark-Name");
    BOOST_CHECK(in1.good());
    BOOST_CHECK_EQUAL(mark2, "");
    BOOST_CHECK(in2.fail());
    BOOST_CHECK_EQUAL(mark3, "0df0-fgh");
    BOOST_CHECK(in3.good());
  }

  BOOST_AUTO_TEST_CASE(test_number)
  {
    std::string number1;
    std::string number2;
    std::string number3;
    std::string number4;
    std::istringstream in1("79114564564\n");
    std::istringstream in2("666.666\n");
    std::istringstream in3("554-367\n");
    std::istringstream in4("554367\n");
    in1 >> tikhonov::Number(number1);
    in2 >> tikhonov::Number(number2);
    in3 >> tikhonov::Number(number3);
    in4 >> tikhonov::Number(number4);
    BOOST_CHECK_EQUAL(number1, "79114564564");
    BOOST_CHECK(in1.good());
    BOOST_CHECK_EQUAL(number2, "");
    BOOST_CHECK(in2.fail());
    BOOST_CHECK_EQUAL(number3, "");
    BOOST_CHECK(in3.fail());
    BOOST_CHECK_EQUAL(number4, "554367");
    BOOST_CHECK(in4.good());
  }

  BOOST_AUTO_TEST_CASE(test_name)
  {
    std::string name1;
    std::string name2;
    std::string name3;
    std::string name4;
    std::istringstream in1("Aleksey\n");
    std::istringstream in2("Aleksey\"\n");
    std::istringstream in3("\"Aleksey\"\n");
    std::istringstream in4("\"Aleksey\n");
    in1 >> tikhonov::Name(name1);
    in2 >> tikhonov::Name(name2);
    in3 >> tikhonov::Name(name3);
    in4 >> tikhonov::Name(name3);
    BOOST_CHECK_EQUAL(name1, "");
    BOOST_CHECK(in1.fail());
    BOOST_CHECK_EQUAL(name2, "");
    BOOST_CHECK(in2.fail());
    BOOST_CHECK_EQUAL(name3, "Aleksey");
    BOOST_CHECK(in3.good());
    BOOST_CHECK_EQUAL(name4, "");
    BOOST_CHECK(in4.fail());
  }

BOOST_AUTO_TEST_SUITE_END()
