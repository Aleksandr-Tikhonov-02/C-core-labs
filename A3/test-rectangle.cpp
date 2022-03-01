#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "base-types.hpp"

const double EPSILON = 0.000001;

BOOST_AUTO_TEST_SUITE(Rectangle)

  BOOST_AUTO_TEST_SUITE(Constructor)

    BOOST_AUTO_TEST_CASE(height_less_than_zero)
    {
      BOOST_CHECK_THROW(tikhonov::Rectangle recatngle({ -5, 5 }, 3, -4), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(width_less_than_zero)
    {
      BOOST_CHECK_THROW(tikhonov::Rectangle recatngle({ -5, 5 }, -3, 4), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(height_is_equal_zero)
    {
      BOOST_CHECK_THROW(tikhonov::Rectangle recatngle({ -5, 5 }, 7, 0), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(width_is_equal_zero)
    {
      BOOST_CHECK_THROW(tikhonov::Rectangle recatngle({ -5, 5 }, 0, 7), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(correct_width_height)
    {
      BOOST_CHECK_NO_THROW(tikhonov::Rectangle recatngle({ -5, 5 }, 5, 7));
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(methods)

    BOOST_AUTO_TEST_CASE(getArea)
    {
      tikhonov::Rectangle rectangle({ 1.1, 2.2 }, 5, 8);
      BOOST_CHECK_CLOSE(rectangle.getArea(), 40, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(getFrameRect)
    {
      tikhonov::Rectangle rectangle({ 10, -5 }, 9, 7);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, 7, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, 9, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, 10, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, -5, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(scale)
    {
      tikhonov::Rectangle rectangle({ 0, 0 }, 12, 5);
      BOOST_CHECK_CLOSE(rectangle.getArea(), 60, EPSILON);
      double posx = rectangle.getFrameRect().pos.x;
      double posy = rectangle.getFrameRect().pos.y;
      rectangle.scale(2);
      BOOST_CHECK_CLOSE(rectangle.getArea(), 2 * 2 * 60, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, posx, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, posy, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(const_width_height_area_when_moved_into_point)
    {
      tikhonov::Rectangle rectangle({ 0, 0 }, 12, 12);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, 12, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, 12, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getArea(), 144, EPSILON);
      rectangle.move({ 5, 5 });
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, 12, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, 12, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getArea(), 144, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(const_width_height_area_when_moving_by_dx_dy)
    {
      tikhonov::Rectangle rectangle({ 0, 0 }, 12, 12);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, 12, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, 12, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getArea(), 144, EPSILON);
      rectangle.move(5, 5);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, 12, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, 12, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getArea(), 144, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(change_frame_pos_when_moved_into_point)
    {
      tikhonov::Rectangle rectangle({ 0, 0 }, 10, 8);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, 0, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, 0, EPSILON);
      rectangle.move({ 9, 3 });
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, 9, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, 3, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(change_frame_pos_when_moving_by_dx_dy)
    {
      tikhonov::Rectangle rectangle({ 0, 0 }, 10, 8);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, 0, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, 0, EPSILON);
      rectangle.move(9, 3);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, 9, EPSILON);
      BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, 3, EPSILON);
    }

  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
