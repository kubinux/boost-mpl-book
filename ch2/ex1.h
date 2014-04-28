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

#ifndef EX1_H_INCLUDED_TFPEGCRZ
#define EX1_H_INCLUDED_TFPEGCRZ

#include <boost/static_assert.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_cv.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/add_volatile.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_array.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/remove_volatile.hpp>

template <typename T,
          typename OldType,
          typename NewType,
          typename IsMatch = typename boost::is_same<T, OldType>::type>
struct replace_type
{
    typedef T type;
};

template <typename T, typename OldType, typename NewType>
struct replace_type<T, OldType, NewType, boost::true_type>
{
    typedef NewType type;
};

template <typename T, typename OldType, typename NewType>
struct replace_type<T const, OldType, NewType, boost::false_type>
{
private:
    typedef typename replace_type<T, OldType, NewType>::type no_const_type;

public:
    typedef typename boost::add_const<no_const_type>::type type;
};

template <typename T, typename OldType, typename NewType>
struct replace_type<T volatile, OldType, NewType, boost::false_type>
{
private:
    typedef typename replace_type<T, OldType, NewType>::type no_volatile_type;

public:
    typedef typename boost::add_volatile<no_volatile_type>::type type;
};

template <typename T, typename OldType, typename NewType>
struct replace_type<T const volatile, OldType, NewType, boost::false_type>
{
private:
    typedef typename replace_type<T, OldType, NewType>::type no_cv_type;

public:
    typedef typename boost::add_cv<no_cv_type>::type type;
};

template <typename T, typename OldType, typename NewType>
struct replace_type<T&, OldType, NewType, boost::false_type>
{
private:
    typedef typename replace_type<T, OldType, NewType>::type no_ref_type;

public:
    typedef typename boost::add_reference<no_ref_type>::type type;
};

template <typename T, typename OldType, typename NewType>
struct replace_type<T*, OldType, NewType, boost::false_type>
{
private:
    typedef typename replace_type<T, OldType, NewType>::type no_ptr_type;

public:
    typedef typename boost::add_pointer<no_ptr_type>::type type;
};

template <typename T, std::size_t Size, typename OldType, typename NewType>
struct replace_type<T[Size], OldType, NewType, boost::false_type>
{
private:
    BOOST_STATIC_ASSERT_MSG(!boost::is_reference<NewType>::value,
                            "array of references not allowed");
    typedef typename replace_type<T, OldType, NewType>::type no_array_type;

public:
    typedef no_array_type type[Size];
};

template <typename T, typename OldType, typename NewType>
struct replace_type<T[], OldType, NewType, boost::false_type>
{
private:
    BOOST_STATIC_ASSERT_MSG(!boost::is_reference<NewType>::value,
                            "array of references not allowed");
    typedef typename replace_type<T, OldType, NewType>::type no_array_type;

public:
    typedef no_array_type type[];
};

template <typename Ret, typename OldType, typename NewType>
struct replace_type<Ret(), OldType, NewType, boost::false_type>
{
private:
    BOOST_STATIC_ASSERT_MSG(!boost::is_array<NewType>::value,
                            "function returning array not allowed");
    typedef typename replace_type<Ret, OldType, NewType>::type return_type;

public:
    typedef return_type type();
};

template <typename Ret, typename Arg1, typename OldType, typename NewType>
struct replace_type<Ret(Arg1), OldType, NewType, boost::false_type>
{
private:
    BOOST_STATIC_ASSERT_MSG(!boost::is_array<NewType>::value,
                            "function returning array not allowed");
    typedef typename replace_type<Ret, OldType, NewType>::type return_type;
    typedef typename replace_type<Arg1, OldType, NewType>::type arg1_type;

public:
    typedef return_type type(arg1_type);
};

template <typename Ret,
          typename Arg1,
          typename Arg2,
          typename OldType,
          typename NewType>
struct replace_type<Ret(Arg1, Arg2), OldType, NewType, boost::false_type>
{
private:
    BOOST_STATIC_ASSERT_MSG(!boost::is_array<NewType>::value,
                            "function returning array not allowed");
    typedef typename replace_type<Ret, OldType, NewType>::type return_type;
    typedef typename replace_type<Arg1, OldType, NewType>::type arg1_type;
    typedef typename replace_type<Arg2, OldType, NewType>::type arg2_type;

public:
    typedef return_type type(arg1_type, arg2_type);
};

template <typename Ret, typename OldType, typename NewType>
struct replace_type<Ret(...), OldType, NewType, boost::false_type>
{
private:
    BOOST_STATIC_ASSERT_MSG(!boost::is_array<NewType>::value,
                            "function returning array not allowed");
    typedef typename replace_type<Ret, OldType, NewType>::type return_type;

public:
    typedef return_type type(...);
};

#endif // include guard

