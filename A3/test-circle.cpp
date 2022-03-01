#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "circle.hpp"
#include "base-types.hpp"

const double EPSILON = 0.000001;

BOOST_AUTO_TEST_SUITE(Circle)

  BOOST_AUTO_TEST_SUITE(Constructor)

    BOOST_AUTO_TEST_CASE(radius_less_than_zero)
    {
      BOOST_CHECK_THROW(tikhonov::Circle circle({ -10, 0 }, -3), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(radius_is_equal_zero)
    {
      BOOST_CHECK_THROW(tikhonov::Circle circle({ 0, 0 }, 0), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(radius_is_correct)
    {
      BOOST_CHECK_NO_THROW(tikhonov::Circle circle({ 0, 0 }, 5));
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(methods)

    BOOST_AUTO_TEST_CASE(getArea)
    {
      tikhonov::Circle circle({ 1.1, 2.2 }, 5);
      BOOST_CHECK_CLOSE(circle.getArea(), 78.539816, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(getFrameRect)
    {
      tikhonov::Circle circle({ 10, -5 }, 8);
      BOOST_CHECK_CLOSE(circle.getFrameRect().height, 16, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().width, 16, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, 10, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, -5, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(scale)
    {
      tikhonov::Circle circle({ 0, 0 }, 7);
      BOOST_CHECK_CLOSE(circle.getArea(), 153.938040, EPSILON);
      double posx = circle.getFrameRect().pos.x;
      double posy = circle.getFrameRect().pos.y;
      circle.scale(2);
      BOOST_CHECK_CLOSE(circle.getArea(), 2 * 2 * 153.938040, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, posx, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, posy, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(const_width_height_area_when_moved_into_point)
    {
      tikhonov::Circle circle({ 0, 0 }, 5);
      BOOST_CHECK_CLOSE(circle.getFrameRect().width, 10, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().height, 10, EPSILON);
      BOOST_CHECK_CLOSE(circle.getArea(), 78.539816, EPSILON);
      circle.move({ 5, 5 });
      BOOST_CHECK_CLOSE(circle.getFrameRect().width, 10, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().height, 10, EPSILON);
      BOOST_CHECK_CLOSE(circle.getArea(), 78.539816, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(const_width_height_area_when_moving_by_dx_dy)
    {
      tikhonov::Circle circle({ 0, 0 }, 8);
      BOOST_CHECK_CLOSE(circle.getFrameRect().width, 16, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().height, 16, EPSILON);
      BOOST_CHECK_CLOSE(circle.getArea(), 201.061929, EPSILON);
      circle.move(5, 5);
      BOOST_CHECK_CLOSE(circle.getFrameRect().width, 16, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().height, 16, EPSILON);
      BOOST_CHECK_CLOSE(circle.getArea(), 201.061929, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(change_frame_pos_when_moved_into_point)
    {
      tikhonov::Circle circle({ 0, 0 }, 5);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, 0, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, 0, EPSILON);
      circle.move({ 9, 3 });
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, 9, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, 3, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(change_frame_pos_when_moving_by_dx_dy)
    {
      tikhonov::Circle circle({ 0, 0 }, 5);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, 0, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, 0, EPSILON);
      circle.move(9, 3);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, 9, EPSILON);
      BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, 3, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
