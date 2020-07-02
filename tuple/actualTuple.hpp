/*
    actualTuple.hpp
    ===============
        Library actualTuple implemention.
*/

#ifndef __YSTL_ACTUALTUPLE_HPP
#define __YSTL_ACTUALTUPLE_HPP

#include "actualTuple.h"

namespace YSTL
{

////////////////////////////////////////////////////////////////////////////////
// Constructor (One Element Tuple)
////////////////////////////////////////////////////////////////////////////////

template <typename T1>
tuple<T1>::tuple() = default;


template <typename T1>
tuple<T1>::tuple(const T1 &first): __PairType(first) {}


////////////////////////////////////////////////////////////////////////////////
// Constructor (Two Elements Tuple)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename T2>
tuple<T1, T2>::tuple() = default;


template <typename T1, typename T2>
tuple<T1, T2>::tuple(const T1 &first, const T2 &second): __PairType(first, second) {}


////////////////////////////////////////////////////////////////////////////////
// Constructor (More Elements Tuple)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename... Types>
tuple<T1, Types...>::tuple() = default;


template <typename T1, typename... Types>
tuple<T1, Types...>::tuple(const T1 &first, const Types &... Args):
    __PairType(first, tuple<Types...>(Args...)) {}


}  // End namespace YSTL


#endif  // __YSTL_ACTUALTUPLE_HPP
