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

#ifndef EX0_H_INCLUDED_KFBWCG0I
#define EX0_H_INCLUDED_KFBWCG0I

#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/add_const.hpp>

template <typename T>
class add_const_ref
{
    typedef typename boost::remove_reference<T>::type no_ref_type;
    typedef typename boost::add_const<no_ref_type>::type const_type;
public:
    typedef const_type& type;
};

#endif // include guard

