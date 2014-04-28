// Copyright (C) 2014 Jakub Lewandowski <jakub.lewandowski@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "ex2.h"
#include <boost/test/unit_test.hpp>

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

