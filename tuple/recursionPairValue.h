/*
    recursionPairValue.h
    ====================
        Library recursionPairValue header.
*/

#ifndef __YSTL_RECURSIONPAIRVALUE_H
#define __YSTL_RECURSIONPAIRVALUE_H

#include "recursionPair.h"
#include "recursionPairType.h"

namespace YSTL
{

////////////////////////////////////////////////////////////////////////////////
// Class __recursionPairValue (Template)
////////////////////////////////////////////////////////////////////////////////

template <int N, typename T>
struct __recursionPairValue;


////////////////////////////////////////////////////////////////////////////////
// Class __recursionPairValue (One Element Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1>
struct __recursionPairValue<0, __recursionPair<T1, void>>
{
    typedef __recursionPair<T1, void> __PairType;
    typedef T1 __ValueType;

    static __ValueType &Get(__PairType &pairObj) { return pairObj.__first; }
    static const __ValueType &Get(const __PairType &pairObj) { return pairObj.__first; }
};


////////////////////////////////////////////////////////////////////////////////
// Class __recursionPairValue (Two Elements Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename T2>
struct __recursionPairValue<0, __recursionPair<T1, T2>>
{
    typedef __recursionPair<T1, T2> __PairType;
    typedef T1 __ValueType;

    static __ValueType &Get(__PairType &pairObj) { return pairObj.__first; }
    static const __ValueType &Get(const __PairType &pairObj) { return pairObj.__first; }
};


template <typename T1, typename T2>
struct __recursionPairValue<1, __recursionPair<T1, T2>>
{
    typedef __recursionPair<T1, T2> __PairType;
    typedef T2 __ValueType;

    static __ValueType &Get(__PairType &pairObj) { return pairObj.__second; }
    static const __ValueType &Get(const __PairType &pairObj) { return pairObj.__second; }
};


////////////////////////////////////////////////////////////////////////////////
// Class __recursionPairValue (Recursion Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename T2, typename T3>
struct __recursionPairValue<0, __recursionPair<T1, __recursionPair<T2, T3>>>
{
    typedef __recursionPair<T1, __recursionPair<T2, T3>> __PairType;
    typedef T1 __ValueType;

    static __ValueType &Get(__PairType &pairObj) { return pairObj.__first; }
    static const __ValueType &Get(const __PairType &pairObj) { return pairObj.__first; }
};


template <typename T1, typename T2, typename T3>
struct __recursionPairValue<1, __recursionPair<T1, __recursionPair<T2, T3>>>
{
    typedef __recursionPair<T1, __recursionPair<T2, T3>> __PairType;
    typedef T2 __ValueType;

    static __ValueType &Get(__PairType &pairObj) { return pairObj.__second.__first; }
    static const __ValueType &Get(const __PairType &pairObj) { return pairObj.__second.__first; }
};


template <int N, typename T1, typename T2, typename T3>
struct __recursionPairValue<N, __recursionPair<T1, __recursionPair<T2, T3>>>
{
    typedef __recursionPair<T1, __recursionPair<T2, T3>> __PairType;
    typedef typename __recursionPairType<N, __PairType>::__ValueType __ValueType;

    static __ValueType &Get(__PairType &pairObj)
    {
        return __recursionPairValue<N - 1, __recursionPair<T2, T3>>::Get(pairObj.__second);
    }


    static const __ValueType &Get(const __PairType &pairObj)
    {
        return __recursionPairValue<N - 1, __recursionPair<T2, T3>>::Get(pairObj.__second);
    }
};


}  // End namespace YSTL


#endif  // __YSTL_RECURSIONPAIRVALUE_H
