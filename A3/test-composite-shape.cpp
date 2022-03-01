#include <boost/test/unit_test.hpp>
#include <memory>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "composite-shape.hpp"
#include "composite-shape-empty.hpp"

const double EPSILON = 0.000001;

BOOST_AUTO_TEST_SUITE(compositeShape)

  BOOST_AUTO_TEST_SUITE(constructors_and_assignment_operators)

    BOOST_AUTO_TEST_CASE(copyConstructor)
    {
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ 0, 0 }, 3, 7);
      tikhonov::CompositeShape array1;
      array1.add(first);
      BOOST_CHECK_NO_THROW(tikhonov::CompositeShape array2(array1));
      tikhonov::CompositeShape array3(array1);
      BOOST_CHECK_CLOSE(array3.getArea(), array1.getArea(), EPSILON);
      BOOST_CHECK_CLOSE(array3.getFrameRect().pos.x, array1.getFrameRect().pos.x, EPSILON);
      BOOST_CHECK_CLOSE(array3.getFrameRect().pos.y, array1.getFrameRect().pos.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(moveConstructor)
    {
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ 0, 0 }, 3, 7);
      tikhonov::CompositeShape array1;
      array1.add(first);
      BOOST_CHECK_NO_THROW(tikhonov::CompositeShape array2(std::move(array1)));
      tikhonov::CompositeShape array3(std::move(array1));
      BOOST_CHECK_THROW(array3.getArea(), std::runtime_error);
      BOOST_CHECK_THROW(array3.getFrameRect(), std::runtime_error);
      BOOST_CHECK_THROW(array3.getFrameRect(), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(CopyAssignmentOperator)
    {
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ 0, 0 }, 3, 7);
      tikhonov::CompositeShape array1;
      array1.add(first);
      BOOST_CHECK_NO_THROW(tikhonov::CompositeShape array2 = array1);
      tikhonov::CompositeShape array3 = array1;
      BOOST_CHECK_CLOSE(array3.getArea(), array1.getArea(), EPSILON);
      BOOST_CHECK_CLOSE(array3.getFrameRect().pos.x, array1.getFrameRect().pos.x, EPSILON);
      BOOST_CHECK_CLOSE(array3.getFrameRect().pos.y, array1.getFrameRect().pos.y, EPSILON);
    }

    BOOST_AUTO_TEST_CASE(MoveAssignmentOperator)
    {
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ 0, 0 }, 3, 7);
      tikhonov::CompositeShape array1;
      array1.add(first);
      BOOST_CHECK_NO_THROW(tikhonov::CompositeShape array2 = std::move(array1));
      tikhonov::CompositeShape array3 = std::move(array1);
      BOOST_CHECK_THROW(array3.getArea(), std::runtime_error);
      BOOST_CHECK_THROW(array3.getFrameRect(), std::runtime_error);
      BOOST_CHECK_THROW(array3.getFrameRect(), std::runtime_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(methods)

    BOOST_AUTO_TEST_CASE(getArea)
    {
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Circle>(tikhonov::point_t{ 0, 0 }, 5);
      std::shared_ptr<tikhonov::Shape> second = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ 0, 10 }, 20, 10);
      std::shared_ptr<tikhonov::Shape> third;
      third = std::make_shared<tikhonov::Triangle>(tikhonov::point_t{ 0, 0 }, tikhonov::point_t{ 10 , 0 }, tikhonov::point_t{ 5, 6 });
      tikhonov::CompositeShape array;
      array.add(first);
      array.add(second);
      array.add(third);
      BOOST_CHECK_CLOSE(array.getArea(), 308.539816, EPSILON);
      tikhonov::CompositeShape array2(std::move(array));
      BOOST_CHECK_THROW(array.getArea(), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(getFrameRect)
    {
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Circle>(tikhonov::point_t{ 0, 0 }, 5);
      std::shared_ptr<tikhonov::Shape> second = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ 0, 10 }, 20, 10);
      std::shared_ptr<tikhonov::Shape> third;
      third = std::make_shared<tikhonov::Triangle>(tikhonov::point_t{ -10, 0 }, tikhonov::point_t{ -5 , 0 }, tikhonov::point_t{ -7.5, 6 });
      tikhonov::CompositeShape array;
      BOOST_CHECK_THROW(array.getFrameRect(), tikhonov::CompositeShapeIsEmpty);
      array.add(first);
      array.add(second);
      array.add(third);
      BOOST_CHECK_CLOSE(array.getFrameRect().height, 20, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().width, 20, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().pos.x, 0, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().pos.y, 5, EPSILON);
      tikhonov::CompositeShape array2(std::move(array));
      BOOST_CHECK_THROW(array.getFrameRect(), std::runtime_error);
      std::shared_ptr<tikhonov::Shape> fourth = std::make_shared<tikhonov::CompositeShape>();
      std::shared_ptr<tikhonov::Shape> fifth = std::make_shared<tikhonov::CompositeShape>();
      tikhonov::CompositeShape array3;
      array3.add(fourth);
      array3.add(fifth);
      BOOST_CHECK_THROW(array3.getFrameRect(), tikhonov::CompositeShapeIsEmpty);
    }

    BOOST_AUTO_TEST_CASE(scale)
    {
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Circle>(tikhonov::point_t{ 0, 0 }, 5);
      std::shared_ptr<tikhonov::Shape> second = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ 0, 10 }, 20, 10);
      std::shared_ptr<tikhonov::Shape> third;
      third = std::make_shared<tikhonov::Triangle>(tikhonov::point_t{ -10, 0 }, tikhonov::point_t{ -5 , 0 }, tikhonov::point_t{ -7.5, 6 });
      tikhonov::CompositeShape array;
      array.add(first);
      array.add(second);
      array.add(third);
      double height = array.getFrameRect().height;
      double width = array.getFrameRect().width;
      double posx = array.getFrameRect().pos.x;
      double posy = array.getFrameRect().pos.y;
      array.scale(2);
      BOOST_CHECK_CLOSE(array.getArea(), first->getArea() + second->getArea() + third->getArea(), EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().height, height * 2, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().width, width * 2, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().pos.x, posx, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().pos.y, posy, EPSILON);
      BOOST_CHECK_THROW(array.scale(-1), std::invalid_argument);
      tikhonov::CompositeShape array2(std::move(array));
      BOOST_CHECK_THROW(array.scale(2), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(const_height_width_area_when_moved_into_point)
    {
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Circle>(tikhonov::point_t{ 0, 0 }, 5);
      std::shared_ptr<tikhonov::Shape> second = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ 0, 10 }, 20, 10);
      std::shared_ptr<tikhonov::Shape> third;
      third = std::make_shared<tikhonov::Triangle>(tikhonov::point_t{ -10, 0 }, tikhonov::point_t{ -5 , 0 }, tikhonov::point_t{ -7.5, 6 });
      tikhonov::CompositeShape array;
      array.add(first);
      array.add(second);
      array.add(third);
      BOOST_CHECK_CLOSE(array.getArea(), 293.539816, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().height, 20, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().width, 20, EPSILON);
      array.move({ 5, 8 });
      BOOST_CHECK_CLOSE(array.getArea(), 293.539816, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().height, 20, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().width, 20, EPSILON);
      tikhonov::CompositeShape array2(std::move(array));
      BOOST_CHECK_THROW(array.move({ 5, 8 }), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(const_height_width_area_when_moving_by_dx_dy)
    {
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Circle>(tikhonov::point_t{ 0, 0 }, 5);
      std::shared_ptr<tikhonov::Shape> second = std::make_shared<tikhonov::Rectangle>(tikhonov::point_t{ 0, 10 }, 20, 10);
      std::shared_ptr<tikhonov::Shape> third;
      third = std::make_shared<tikhonov::Triangle>(tikhonov::point_t{ -10, 0 }, tikhonov::point_t{ -5 , 0 }, tikhonov::point_t{ -7.5, 6 });
      tikhonov::CompositeShape array;
      array.add(first);
      array.add(second);
      array.add(third);
      BOOST_CHECK_CLOSE(array.getArea(), 293.539816, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().height, 20, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().width, 20, EPSILON);
      array.move(5, 8);
      BOOST_CHECK_CLOSE(array.getArea(), 293.539816, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().height, 20, EPSILON);
      BOOST_CHECK_CLOSE(array.getFrameRect().width, 20, EPSILON);
      tikhonov::CompositeShape array2(std::move(array));
      BOOST_CHECK_THROW(array.move(5, 8), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(add)
    {
      tikhonov::CompositeShape array;
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Circle>(tikhonov::point_t{ 0, 0 }, 5);
      BOOST_CHECK_NO_THROW(array.add(first));
      BOOST_CHECK_THROW(array.add(nullptr), std::invalid_argument);
      BOOST_CHECK_CLOSE(array.getArea(), 78.539816, EPSILON);
      tikhonov::CompositeShape array2(std::move(array));
      BOOST_CHECK_THROW(array.add(first), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(index_operator)
    {
      tikhonov::CompositeShape array;
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Circle>(tikhonov::point_t{ 0, 0 }, 5);
      array.add(first);
      BOOST_CHECK_THROW(array[1], std::out_of_range);
      BOOST_CHECK_NO_THROW(array[0]);
      tikhonov::CompositeShape array2 = std::move(array);
      BOOST_CHECK_THROW(array[0], std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(remove)
    {
      tikhonov::CompositeShape array;
      BOOST_CHECK_THROW(array.remove(0), std::runtime_error);
      std::shared_ptr<tikhonov::Shape> first = std::make_shared<tikhonov::Circle>(tikhonov::point_t{ 0, 0 }, 5);
      array.add(first);
      BOOST_CHECK_THROW(array.remove(1), std::out_of_range);
      BOOST_CHECK_NO_THROW(array.remove(0));
      tikhonov::CompositeShape array2(std::move(array));
      BOOST_CHECK_THROW(array.remove(0), std::runtime_error);
    }

  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
