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

#include "quantity.h"
#include "dimension.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(addition)
{
    ch3::quantity<float, ch3::velocity> v1(2.0f);
    ch3::quantity<float, ch3::velocity> v2(1.0f);
    ch3::quantity<float, ch3::velocity> sum = v1 + v2;
    BOOST_CHECK_CLOSE(3.0f, sum.value(), 10e-6);
}

BOOST_AUTO_TEST_CASE(subtraction)
{
    ch3::quantity<float, ch3::velocity> delta =
        ch3::quantity<float, ch3::velocity>(4.0f) -
        ch3::quantity<float, ch3::velocity>(2.0f);
    BOOST_CHECK_CLOSE(2.0f, delta.value(), 10e-6);
}

BOOST_AUTO_TEST_CASE(multiplication)
{
    ch3::quantity<float, ch3::mass> m(5.0f);
    ch3::quantity<float, ch3::acceleration> a(9.8f);
    ch3::quantity<float, ch3::force> f = m * a;
    BOOST_CHECK_CLOSE(5.0f * 9.8f, f.value(), 10e-6);
}

BOOST_AUTO_TEST_CASE(division)
{
    ch3::quantity<float, ch3::acceleration> a(9.8f);
    ch3::quantity<float, ch3::force> f(5.0f * 9.8f);
    ch3::quantity<float, ch3::mass> m = f / a;
    BOOST_CHECK_CLOSE(5.0f, m.value(), 10e-6);
}

