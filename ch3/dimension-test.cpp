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

#include "dimension.h"
#include <boost/test/unit_test.hpp>
#include <boost/type_traits/is_same.hpp>

BOOST_AUTO_TEST_CASE(multiply_dimensions)
{
    BOOST_CHECK((boost::is_same<
        boost::mpl::vector3_c<int, 1, 1, 0>,
        ch3::multiply_dimensions<ch3::mass, ch3::length>::type>::value));
}

BOOST_AUTO_TEST_CASE(divide_dimensions)
{
    BOOST_CHECK((boost::is_same<
        ch3::velocity,
        ch3::divide_dimensions<ch3::length, ch3::time>::type>::value));
}

