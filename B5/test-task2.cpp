#include <boost/test/unit_test.hpp>
#include <sstream>

#include "task2.hpp"

BOOST_AUTO_TEST_SUITE(testTask2)
BOOST_AUTO_TEST_CASE(test)
{
  std::istringstream in("4 (0;0) (0;8) (4;4) (8;0)\n\n4 (0;0) (1;0) (1;8) (0;8)\n\n\n\n3 (1;     7) (1; \t4)\t(3; 7)\n"
    "5 (0;0) (0;2) (1;0) (1;2) (3;1)\n \t\n\n\n4 (0; 0) (0; 1) (1; 1) (1; 0)");
  std::ostringstream out;
  tikhonov::task2(in, out);
  BOOST_CHECK_EQUAL(out.str(), "Vertices: 20\nTriangles: 1\nSquares: 1\nRectangles: 2\nPoints: (0; 0) (0; 0) (1; 7) (0; 0)"
    " \nShapes:\n3 (1; 7) (1; 4) (3; 7) \n4 (0; 0) (0; 1) (1; 1) (1; 0) \n4 (0; 0) (0; 8) (4; 4) (8; 0) \n4 (0; 0) (1; 0) (1; 8) (0; 8) \n");
}
BOOST_AUTO_TEST_SUITE_END()
