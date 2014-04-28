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

#ifndef EX3_H_INCLUDED_7YEDXMK5
#define EX3_H_INCLUDED_7YEDXMK5

#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_volatile.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <ostream>

namespace detail
{

    template <typename T,
              typename IsConst = typename boost::is_const<T>::type,
              typename IsVolatile = typename boost::is_volatile<T>::type,
              typename IsPointer = typename boost::is_pointer<T>::type,
              typename IsReference = typename boost::is_reference<T>::type>
    struct type_descriptor_printer
    {
        void operator()(std::ostream& os) const
        {
            os << "unknown";
        }
    };

    template <> struct type_descriptor_printer<char>
    {
        void operator()(std::ostream& os) const
        {
            os << "char";
        }
    };

    template <> struct type_descriptor_printer<short int>
    {
        void operator()(std::ostream& os) const
        {
            os << "short";
        }
    };

    template <> struct type_descriptor_printer<int>
    {
        void operator()(std::ostream& os) const
        {
            os << "int";
        }
    };

    template <> struct type_descriptor_printer<long int>
    {
        void operator()(std::ostream& os) const
        {
            os << "long";
        }
    };

    template <typename T>
    struct type_descriptor_printer<T, boost::true_type, boost::true_type>
    {
        void operator()(std::ostream& os) const
        {
            typedef typename boost::remove_cv<T>::type underlying_type;
            type_descriptor_printer<underlying_type> printer;
            printer(os);
            os << " const volatile";
        }
    };

    template <typename T>
    struct type_descriptor_printer<T, boost::true_type, boost::false_type>
    {
        void operator()(std::ostream& os) const
        {
            typedef typename boost::remove_cv<T>::type underlying_type;
            type_descriptor_printer<underlying_type> printer;
            printer(os);
            os << " const";
        }
    };

    template <typename T>
    struct type_descriptor_printer<T, boost::false_type, boost::true_type>
    {
        void operator()(std::ostream& os) const
        {
            typedef typename boost::remove_cv<T>::type underlying_type;
            type_descriptor_printer<underlying_type> printer;
            printer(os);
            os << " volatile";
        }
    };

    template <typename T>
    struct type_descriptor_printer<T,
                                   boost::false_type,
                                   boost::false_type,
                                   boost::true_type>
    {
        void operator()(std::ostream& os) const
        {
            typedef typename boost::remove_pointer<T>::type underlying_type;
            type_descriptor_printer<underlying_type> printer;
            printer(os);
            os << "*";
        }
    };

    template <typename T>
    struct type_descriptor_printer<T,
                                   boost::false_type,
                                   boost::false_type,
                                   boost::false_type,
                                   boost::true_type>
    {
        void operator()(std::ostream& os) const
        {
            typedef typename boost::remove_reference<T>::type underlying_type;
            type_descriptor_printer<underlying_type> printer;
            printer(os);
            os << "&";
        }
    };

} // close detail namespace

template <typename T> struct type_descriptor
{
};

template <typename T>
std::ostream& operator<<(std::ostream& os, type_descriptor<T>)
{
    detail::type_descriptor_printer<T> printer;
    printer(os);
    return os;
}

#endif // include guard

