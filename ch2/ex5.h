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

#ifndef EX5_H_INCLUDED_470WVIB1
#define EX5_H_INCLUDED_470WVIB1

#include <ostream>

namespace ex5
{

    namespace detail
    {

        template <typename T> struct type_printer
        {
            void operator()(std::ostream& os) const
            {
                os << "unknown";
            }
        };

#define ex5_local_FUNDAMENTAL_TYPE_PRINTER(type)                              \
    template <> struct type_printer<type>                                     \
    {                                                                         \
        void operator()(std::ostream & os) const                              \
        {                                                                     \
            os << #type;                                                      \
        }                                                                     \
    }

        ex5_local_FUNDAMENTAL_TYPE_PRINTER(char);
        ex5_local_FUNDAMENTAL_TYPE_PRINTER(short int);
        ex5_local_FUNDAMENTAL_TYPE_PRINTER(int);
        ex5_local_FUNDAMENTAL_TYPE_PRINTER(long int);
#undef ex5_local_FUNDAMENTAL_TYPE_PRINTER

#define ex5_local_CV_TYPE_PRINTER(qualifiers)                                 \
    template <typename T> struct type_printer<T qualifiers>                   \
    {                                                                         \
        void operator()(std::ostream & os) const                              \
        {                                                                     \
            os << #qualifiers " ";                                            \
            type_printer<T>()(os);                                            \
        }                                                                     \
    }

        ex5_local_CV_TYPE_PRINTER(const);
        ex5_local_CV_TYPE_PRINTER(volatile);
        ex5_local_CV_TYPE_PRINTER(const volatile);
#undef ex5_local_CV_TYPE_PRINTER

        template <typename T> struct type_printer<T*>
        {
            void operator()(std::ostream& os) const
            {
                os << "pointer to ";
                type_printer<T>()(os);
            }
        };

        template <typename T> struct type_printer<T&>
        {
            void operator()(std::ostream& os) const
            {
                os << "reference to ";
                type_printer<T>()(os);
            }
        };

        template <typename T> struct type_printer<T[]>
        {
            void operator()(std::ostream& os) const
            {
                os << "array of ";
                type_printer<T>()(os);
            }
        };

        template <typename T, std::size_t N> struct type_printer<T[N]>
        {
            void operator()(std::ostream& os) const
            {
                os << "array (size " << N << ") of ";
                type_printer<T>()(os);
            }
        };

        template <typename Ret> struct type_printer<Ret()>
        {
            void operator()(std::ostream& os) const
            {
                os << "function of () returning ";
                type_printer<Ret>()(os);
            }
        };

        template <typename Ret, typename Arg1> struct type_printer<Ret(Arg1)>
        {
            void operator()(std::ostream& os) const
            {
                os << "function of (";
                type_printer<Arg1>()(os);
                os << ") returning ";
                type_printer<Ret>()(os);
            }
        };

        template <typename Ret, typename Arg1, typename Arg2>
        struct type_printer<Ret(Arg1, Arg2)>
        {
            void operator()(std::ostream& os) const
            {
                os << "function of (";
                type_printer<Arg1>()(os);
                os << ", ";
                type_printer<Arg2>()(os);
                os << ") returning ";
                type_printer<Ret>()(os);
            }
        };

    } // close detail namespace

    template <typename T>
    struct type_descriptor
    {
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, type_descriptor<T>)
    {
        detail::type_printer<T>()(os);
        return os;
    }

} // close ex5 namespace

#endif // include guard

