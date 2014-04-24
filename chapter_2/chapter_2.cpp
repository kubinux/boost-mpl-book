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
#include "exercise_3.h"
#include <boost/type_traits/is_same.hpp>

#define BOOST_TEST_MODULE chapter_2
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <sstream>

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

BOOST_AUTO_TEST_CASE(ex_3_float)
{
    std::ostringstream os;
    os << type_descriptor<float>();
    BOOST_CHECK_EQUAL("unknown", os.str());
}

BOOST_AUTO_TEST_CASE(ex_3_float_const_ref)
{
    std::ostringstream os;
    os << type_descriptor<float const&>();
    BOOST_CHECK_EQUAL("unknown const&", os.str());
}

BOOST_AUTO_TEST_CASE(ex_3_char)
{
    std::ostringstream os;
    os << type_descriptor<char>();
    BOOST_CHECK_EQUAL("char", os.str());
}

BOOST_AUTO_TEST_CASE(ex_3_char_const)
{
    std::ostringstream os;
    os << type_descriptor<char const>();
    BOOST_CHECK_EQUAL("char const", os.str());
}

BOOST_AUTO_TEST_CASE(ex_3_int_volatile)
{
    std::ostringstream os;
    os << type_descriptor<int volatile>();
    BOOST_CHECK_EQUAL("int volatile", os.str());
}

BOOST_AUTO_TEST_CASE(ex_3_long_const_volatile)
{
    std::ostringstream os;
    os << type_descriptor<long const volatile>();
    BOOST_CHECK_EQUAL("long const volatile", os.str());
}

BOOST_AUTO_TEST_CASE(ex_3_short_const_volatile_pointer_const_ref)
{
    std::ostringstream os;
    os << type_descriptor<short const volatile* const&>();
    BOOST_CHECK_EQUAL("short const volatile* const&", os.str());
}

