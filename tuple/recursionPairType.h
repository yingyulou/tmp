/*
    recursionPairType.h
    ===================
        Library recursionPairType header.
*/

#ifndef __YSTL_RECURSIONPAIRTYPE_H
#define __YSTL_RECURSIONPAIRTYPE_H

#include "recursionPair.h"

namespace YSTL
{

////////////////////////////////////////////////////////////////////////////////
// Class __recursionPairType (Template)
////////////////////////////////////////////////////////////////////////////////

template <int N, typename T>
struct __recursionPairType;


////////////////////////////////////////////////////////////////////////////////
// Class __recursionPairType (One Element Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1>
struct __recursionPairType<0, __recursionPair<T1, void>>
{
    typedef T1 __ValueType;
};


////////////////////////////////////////////////////////////////////////////////
// Class __recursionPairType (Two Elements Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename T2>
struct __recursionPairType<0, __recursionPair<T1, T2>>
{
    typedef T1 __ValueType;
};


template <typename T1, typename T2>
struct __recursionPairType<1, __recursionPair<T1, T2>>
{
    typedef T2 __ValueType;
};


////////////////////////////////////////////////////////////////////////////////
// Class __recursionPairType (Recursion Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename T2, typename T3>
struct __recursionPairType<0, __recursionPair<T1, __recursionPair<T2, T3>>>
{
    typedef T1 __ValueType;
};


template <typename T1, typename T2, typename T3>
struct __recursionPairType<1, __recursionPair<T1, __recursionPair<T2, T3>>>
{
    typedef T2 __ValueType;
};


template <int N, typename T1, typename T2, typename T3>
struct __recursionPairType<N, __recursionPair<T1, __recursionPair<T2, T3>>>
{
    typedef typename __recursionPairType<N - 1, __recursionPair<T2, T3>>::__ValueType __ValueType;
};


}  // End namespace YSTL


#endif  // __YSTL_RECURSIONPAIRTYPE_H
