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

#ifndef DIMENSION_H_INCLUDED_RUMDMNY3
#define DIMENSION_H_INCLUDED_RUMDMNY3

#include <boost/mpl/int.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/at.hpp>

namespace ch3
{

    typedef boost::mpl::vector3_c<int, 1, 0, 0> mass;
    typedef boost::mpl::vector3_c<int, 0, 1, 0> length;
    typedef boost::mpl::vector3_c<int, 0, 0, 1> time;

    typedef boost::mpl::vector3_c<int, 0, 1, -1> velocity;
    typedef boost::mpl::vector3_c<int, 0, 1, -2> acceleration;
    typedef boost::mpl::vector3_c<int, 1, 1, -1> momentum;
    typedef boost::mpl::vector3_c<int, 1, 1, -2> force;

    namespace detail
    {

        template <typename S>
        struct sequence_to_vector3_c
        {
            typedef boost::mpl::vector3_c<
                int,
                boost::mpl::at<S, boost::mpl::int_<0> >::type::value,
                boost::mpl::at<S, boost::mpl::int_<1> >::type::value,
                boost::mpl::at<S, boost::mpl::int_<2> >::type::value> type;
        };

    } // close detail namespace

    template <typename D1, typename D2>
    struct multiply_dimensions
        : detail::sequence_to_vector3_c<typename boost::mpl::transform<
              D1,
              D2,
              boost::mpl::plus<boost::mpl::placeholders::_1,
                               boost::mpl::placeholders::_2> >::type>
    {
    };

    template <typename D1, typename D2>
    struct divide_dimensions
        : detail::sequence_to_vector3_c<typename boost::mpl::transform<
              D1,
              D2,
              boost::mpl::minus<boost::mpl::placeholders::_1,
                                boost::mpl::placeholders::_2> >::type>
    {
    };

} // close ch3 namespace

#endif // include guard

