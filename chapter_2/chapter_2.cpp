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

#include "exercise_0.h"
#include <boost/type_traits/is_same.hpp>

#define BOOST_TEST_MODULE chapter_2
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(ex_0_non_reference)
{
    typedef int arg_type;
    typedef int const& expected_type;
    typedef add_const_ref<arg_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(ex_0_reference)
{
    typedef int& arg_type;
    typedef int& expected_type;
    typedef add_const_ref<arg_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(ex_0_const_reference)
{
    typedef int const& arg_type;
    typedef int const& expected_type;
    typedef add_const_ref<arg_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

