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

#ifndef QUANTITY_H_INCLUDED_AOQ1OIK8
#define QUANTITY_H_INCLUDED_AOQ1OIK8

#include "dimension.h"

namespace ch3
{

    template <typename T, typename Dim>
    struct quantity
    {
        explicit quantity(T val)
        : value_(val)
        {
        }

        T value() const
        {
            return value_;
        }

    private:
        T value_;
    };

    template <typename T, typename Dim>
    quantity<T, Dim> operator+(quantity<T, Dim> a, quantity<T, Dim> b)
    {
        return quantity<T, Dim>(a.value() + b.value());
    }

    template <typename T, typename Dim>
    quantity<T, Dim> operator-(quantity<T, Dim> a, quantity<T, Dim> b)
    {
        return quantity<T, Dim>(a.value() - b.value());
    }

    template <typename T, typename Dim1, typename Dim2>
    quantity<T, typename multiply_dimensions<Dim1, Dim2>::type>
    operator*(quantity<T, Dim1> a, quantity<T, Dim2> b)
    {
        return quantity<T, typename multiply_dimensions<Dim1, Dim2>::type>(
            a.value() * b.value());
    }

    template <typename T, typename Dim1, typename Dim2>
    quantity<T, typename divide_dimensions<Dim1, Dim2>::type>
    operator/(quantity<T, Dim1> a, quantity<T, Dim2> b)
    {
        return quantity<T, typename divide_dimensions<Dim1, Dim2>::type>(
            a.value() / b.value());
    }

} // close ch3 namespace

#endif // include guard

