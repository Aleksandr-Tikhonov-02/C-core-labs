#include <sstream>
#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "DataStruct.hpp"

BOOST_AUTO_TEST_SUITE(test_dataStruct_readers)

  BOOST_AUTO_TEST_CASE(correct_imput)
  {
    std::istringstream in("5, 5, aa\n-4, 0, a\n");
    tikhonov::DataStruct ds1, ds2;
    in >> ds1 >> ds2;
    BOOST_CHECK(in.good());
    BOOST_CHECK_EQUAL(ds1.key1, 5);
    BOOST_CHECK_EQUAL(ds1.key2, 5);
    BOOST_CHECK_EQUAL(ds1.str, "aa");
    BOOST_CHECK_EQUAL(ds2.key1, -4);
    BOOST_CHECK_EQUAL(ds2.key2, 0);
    BOOST_CHECK_EQUAL(ds2.str, "a");
  }
  
  BOOST_AUTO_TEST_SUITE(incorrect_imput)

    BOOST_AUTO_TEST_CASE(invalid_key_1)
    {
      std::istringstream in("f, 5, aa\n-4, 0, a\n");
      tikhonov::DataStruct ds1, ds2;
      in >> ds1 >> ds2;
      BOOST_CHECK(in.fail());
    }

    BOOST_AUTO_TEST_CASE(invalid_key_1_more_than_abs_5)
    {
      std::istringstream in("10, 5, aa\n-4, 0, a\n");
      tikhonov::DataStruct ds1, ds2;
      in >> ds1 >> ds2;
      BOOST_CHECK(in.fail());
    }

    BOOST_AUTO_TEST_CASE(invalid_key_2)
    {
      std::istringstream in("5, f, aa\n-4, 0, a\n");
      tikhonov::DataStruct ds1, ds2;
      in >> ds1 >> ds2;
      BOOST_CHECK(in.fail());
    }

    BOOST_AUTO_TEST_CASE(invalid_key_2_more_than_abs_5)
    {
      std::istringstream in("5, 10, aa\n-4, 0, a\n");
      tikhonov::DataStruct ds1, ds2;
      in >> ds1 >> ds2;
      BOOST_CHECK(in.fail());
    }

    BOOST_AUTO_TEST_CASE(no_delimeter)
    {
      std::istringstream in("5 10, aa\n-4, 0, a\n");
      tikhonov::DataStruct ds1, ds2;
      in >> ds1 >> ds2;
      BOOST_CHECK(in.fail());
    }
  
  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_CASE(check_output)
  {
    tikhonov::DataStruct ds1 = { 5, 5, "aa" };
    tikhonov::DataStruct ds2 = { -4, -3, "a" };
    std::ostringstream out;
    out << ds1 << '\n' << ds2;
    BOOST_CHECK_EQUAL(out.str(), "5, 5, aa\n-4, -3, a");
  }

BOOST_AUTO_TEST_SUITE_END()
