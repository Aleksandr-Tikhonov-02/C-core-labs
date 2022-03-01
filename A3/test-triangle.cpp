#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "triangle.hpp"
#include "base-types.hpp"

const double EPSILON = 0.000001;

BOOST_AUTO_TEST_SUITE(Triangle)

  BOOST_AUTO_TEST_SUITE(Constructor)

    BOOST_AUTO_TEST_CASE(triangle_is_a_dot)
    {
      BOOST_CHECK_THROW(tikhonov::Triangle triangle({ -5, 5 }, { -5, 5}, { -5, 5 }), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(triangle_is_a_line)
    {
      BOOST_CHECK_THROW(tikhonov::Triangle triangle({ 0, 0 }, { 0, 5 }, { 0, 10 }), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(correct_data)
    {
      BOOST_CHECK_NO_THROW(tikhonov::Triangle triangle({ -5, 5 }, { 0, 0 }, { 4, 8 }));
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(methods)

    BOOST_AUTO_TEST_CASE(getArea)
    {
        tikhonov::Triangle triangle({ 0, 0 }, { 0, 10 }, { 5, 5 });
        BOOST_CHECK_CLOSE(triangle.getArea(), 25, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(getFrameRect)
    {
      tikhonov::Triangle triangle({ 0, 0 }, { 0, 10 }, { 9, 5 });
      BOOST_CHECK_CLOSE(triangle.getFrameRect().height, 10, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().width, 9, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.x, 3, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.y, 5, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(scale)
    {
      tikhonov::Triangle triangle({ 0, 0 }, { 10, 0 }, { 5, 9 });
      BOOST_CHECK_CLOSE(triangle.getArea(), 45, EPSILON);
      double posx = triangle.getFrameRect().pos.x;
      double posy = triangle.getFrameRect().pos.y;
      triangle.scale(2);
      BOOST_CHECK_CLOSE(triangle.getArea(), 2 * 2 * 45, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.x, posx, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.y, posy, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(const_width_height_area_when_moved_into_point)
    {
      tikhonov::Triangle triangle({ 0, 0 }, { 0, 10 }, { 9, 5 });
      BOOST_CHECK_CLOSE(triangle.getFrameRect().width, 9, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().height, 10, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getArea(), 45, EPSILON);
      triangle.move({ 5, 5 });
      BOOST_CHECK_CLOSE(triangle.getFrameRect().width, 9, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().height, 10, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getArea(), 45, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(const_width_height_area_when_moving_by_dx_dy)
    {
      tikhonov::Triangle triangle({ 0, 0 }, { 0, 10 }, { 9, 5 });
      BOOST_CHECK_CLOSE(triangle.getFrameRect().width, 9, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().height, 10, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getArea(), 45, EPSILON);
      triangle.move(5, 5);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().width, 9, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().height, 10, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getArea(), 45, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(change_frame_pos_when_moved_into_point)
    {
      tikhonov::Triangle triangle({ -3, -2 }, { 3, -2 }, { 0, 4 });
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.x, 0, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.y, 0, EPSILON);
      triangle.move({ 9, 3 });
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.x, 9, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.y, 3, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(change_frame_pos_when_moving_by_dx_dy)
    {
      tikhonov::Triangle triangle({ 0, 0 }, { 0, 10 }, { 9, 5 });
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.x, 3, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.y, 5, EPSILON);
      triangle.move(9, 3);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.x, 12, EPSILON);
      BOOST_CHECK_CLOSE(triangle.getFrameRect().pos.y, 8, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
