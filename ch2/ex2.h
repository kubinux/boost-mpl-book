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

#ifndef EX2_H_INCLUDED_JUWN1C4K
#define EX2_H_INCLUDED_JUWN1C4K

#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/add_pointer.hpp>

#include <cassert>

namespace ex2
{

    template <typename Target, typename Source>
    Target polymorphic_downcast(Source& src)
    {
        typedef typename boost::remove_reference<Target>::type target_no_ref;
        typedef typename boost::add_pointer<target_no_ref>::type target_ptr;
        assert(dynamic_cast<target_ptr>(&src) == &src);
        return *static_cast<target_ptr>(&src);
    }

    template <typename Target, typename Source>
    Target polymorphic_downcast(Source* src)
    {
        assert(dynamic_cast<Target>(src) == src);
        return static_cast<Target>(src);
    }

} // close ex2 namespace

#endif // include guard

