/*
    recursionPair.hpp
    =================
        Library recursionPair implemention.
*/

#ifndef __YSTL_RECURSIONPAIR_HPP
#define __YSTL_RECURSIONPAIR_HPP

#include "recursionPair.h"

namespace YSTL
{

////////////////////////////////////////////////////////////////////////////////
// Constructor (Two Or More Elements Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename T2>
__recursionPair<T1, T2>::__recursionPair() = default;


template <typename T1, typename T2>
__recursionPair<T1, T2>::__recursionPair(const T1 &first, const T2 &second):
    __first(first), __second(second) {}


////////////////////////////////////////////////////////////////////////////////
// Constructor (One Element Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1>
__recursionPair<T1, void>::__recursionPair() = default;


template <typename T1>
__recursionPair<T1, void>::__recursionPair(const T1 &first): __first(first) {}


}  // End namespace YSTL


#endif  // __YSTL_RECURSIONPAIR_HPP
