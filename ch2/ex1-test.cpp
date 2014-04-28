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

#include "ex1.h"
#include <boost/test/unit_test.hpp>
#include <boost/type_traits/is_same.hpp>

BOOST_AUTO_TEST_CASE(int_replace_float_to_char)
{
    typedef int arg_type;
    typedef float old_type;
    typedef char new_type;
    typedef int expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_replace_int_to_char)
{
    typedef int arg_type;
    typedef int old_type;
    typedef char new_type;
    typedef char expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_const_replace_int_to_char)
{
    typedef int const arg_type;
    typedef int old_type;
    typedef char new_type;
    typedef char const expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_const_replace_int_const_to_char)
{
    typedef int const arg_type;
    typedef int const old_type;
    typedef char new_type;
    typedef char expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_volatile_replace_int_volatile_to_char_cv)
{
    typedef int volatile arg_type;
    typedef int volatile old_type;
    typedef char const volatile new_type;
    typedef char const volatile expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_volatile_replace_int_to_char_cv)
{
    typedef int volatile arg_type;
    typedef int old_type;
    typedef char const volatile new_type;
    typedef char const volatile expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_const_volatile_replace_int_volatile_to_char)
{
    typedef int const volatile arg_type;
    typedef int volatile old_type;
    typedef char new_type;
    typedef int const volatile expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_ref_replace_int_to_char)
{
    typedef int& arg_type;
    typedef int old_type;
    typedef char new_type;
    typedef char& expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_ref_replace_int_to_char_const_ref)
{
    typedef int& arg_type;
    typedef int old_type;
    typedef char const& new_type;
    typedef char const& expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_ptr_replace_int_to_char)
{
    typedef int* arg_type;
    typedef int old_type;
    typedef char new_type;
    typedef char* expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_ptr_replace_int_to_char_ref)
{
    typedef int* arg_type;
    typedef int old_type;
    typedef char& new_type;
    typedef char* expected_type;
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_array_3_replace_int_to_char)
{
    typedef int arg_type[3];
    typedef int old_type;
    typedef char new_type;
    typedef char expected_type[3];
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_ptr_array_3_replace_int_to_char)
{
    typedef int* arg_type[3];
    typedef int old_type;
    typedef char new_type;
    typedef char* expected_type[3];
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_ptr_array_3_replace_int_ptr_to_char_ptr)
{
    typedef int* arg_type[3];
    typedef int* old_type;
    typedef char* new_type;
    typedef char* expected_type[3];
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_ptr_array_3_replace_int_ptr_to_char_const)
{
    typedef int* arg_type[3];
    typedef int* old_type;
    typedef char const new_type;
    typedef char const expected_type[3];
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(int_array_replace_int_to_char_const)
{
    typedef int arg_type[];
    typedef int old_type;
    typedef char const new_type;
    typedef char const expected_type[];
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(func_returning_int_replace_int_to_char)
{
    typedef int arg_type();
    typedef int old_type;
    typedef char new_type;
    typedef char expected_type();
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(book_example_1)
{
    typedef int const* arg_type[10];
    typedef int const old_type;
    typedef long new_type;
    typedef long* expected_type[10];
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

BOOST_AUTO_TEST_CASE(book_example_2)
{
    typedef char& (*arg_type)(char&);
    typedef char& old_type;
    typedef long& new_type;
    typedef long& (*expected_type)(long&);
    typedef replace_type<arg_type, old_type, new_type>::type actual_type;

    bool const is_same = boost::is_same<expected_type, actual_type>::value;
    BOOST_CHECK(is_same);
}

