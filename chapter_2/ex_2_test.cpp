#define BOOST_TEST_MODULE chapter_2_ex_2
#include <boost/test/unit_test.hpp>

#include "exercise_2.h"

namespace
{

    struct base
    {
        virtual ~base()
        {
        }
    };

    struct derived : base
    {
    };

} // close unnamed namespace

BOOST_AUTO_TEST_CASE(pointer_to_pointer)
{
    derived d;
    base* b_ptr = &d;
    derived* d_ptr = ex2::polymorphic_downcast<derived*>(b_ptr);
    BOOST_CHECK(d_ptr == &d);
}

BOOST_AUTO_TEST_CASE(reference_to_reference)
{
    derived d;
    base& b_ref = d;
    derived& d_ref = ex2::polymorphic_downcast<derived&>(b_ref);
    BOOST_CHECK(&d_ref == &d);
}

BOOST_AUTO_TEST_CASE(reference_to_const_reference)
{
    derived d;
    base& b_ref = d;
    derived const& d_ref = ex2::polymorphic_downcast<derived const&>(b_ref);
    BOOST_CHECK(&d_ref == &d);
}

BOOST_AUTO_TEST_CASE(const_reference_to_const_reference)
{
    derived d;
    base const& b_ref = d;
    derived const& d_ref = ex2::polymorphic_downcast<derived const&>(b_ref);
    BOOST_CHECK(&d_ref == &d);
}

BOOST_AUTO_TEST_CASE(pointer_by_const_reference_to_pointer)
{
    derived d;
    base* const& b_ptr = &d;
    derived* d_ref = ex2::polymorphic_downcast<derived*>(b_ptr);
    BOOST_CHECK(d_ref == &d);
}

