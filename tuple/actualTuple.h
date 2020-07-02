/*
    actualTuple.h
    =============
        Library actualTuple header.
*/

#ifndef __YSTL_ACTUALTUPLE_H
#define __YSTL_ACTUALTUPLE_H

#include "recursionPair.h"
#include "recursionPairType.h"
#include "recursionPairValue.h"

namespace YSTL
{

////////////////////////////////////////////////////////////////////////////////
// Class tuple (Template)
////////////////////////////////////////////////////////////////////////////////

template <typename... Types>
struct tuple;


////////////////////////////////////////////////////////////////////////////////
// Class tuple (One Element Tuple)
////////////////////////////////////////////////////////////////////////////////

template <typename T1>
struct tuple<T1>: __recursionPair<T1, void>
{
    // typedef
    typedef __recursionPair<T1, void> __PairType;


    // Constructor
    tuple();
    tuple(const T1 &first);
};


////////////////////////////////////////////////////////////////////////////////
// Class tuple (Two Elements Tuple)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename T2>
struct tuple<T1, T2>: __recursionPair<T1, T2>
{
    // typedef
    typedef __recursionPair<T1, T2> __PairType;


    // Constructor
    tuple();
    tuple(const T1 &first, const T2 &second);
};


////////////////////////////////////////////////////////////////////////////////
// Class tuple (More Elements Tuple)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename... Types>
struct tuple<T1, Types...>: __recursionPair<T1, typename tuple<Types...>::__PairType>
{
    // typedef
    typedef __recursionPair<T1, typename tuple<Types...>::__PairType> __PairType;


    // Constructor
    tuple();
    tuple(const T1 &first, const Types &... Args);
};


////////////////////////////////////////////////////////////////////////////////
// Class tuple_size
////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct tuple_size;


template <typename... Types>
struct tuple_size<tuple<Types...>>
{
    static constexpr int value = sizeof...(Types);
};


////////////////////////////////////////////////////////////////////////////////
// Class tuple_element
////////////////////////////////////////////////////////////////////////////////

template <int N, typename T>
struct tuple_element;


template <int N, typename... Types>
struct tuple_element<N, tuple<Types...>>
{
    typedef typename __recursionPairType<N, typename tuple<Types...>::__PairType>::__ValueType type;
};


////////////////////////////////////////////////////////////////////////////////
// make_tuple
////////////////////////////////////////////////////////////////////////////////

template <typename... Types>
inline tuple<Types...> make_tuple(const Types &... Args)
{
    return tuple<Types...>(Args...);
}


////////////////////////////////////////////////////////////////////////////////
// get
////////////////////////////////////////////////////////////////////////////////

template <int N, typename... Types>
inline typename tuple_element<N, tuple<Types...>>::type &get(tuple<Types...> &tupleObj)
{
    return __recursionPairValue<N, typename tuple<Types...>::__PairType>::Get(tupleObj);
}


template <int N, typename... Types>
inline const typename tuple_element<N, tuple<Types...>>::type &get(const tuple<Types...> &tupleObj)
{
    return __recursionPairValue<N, typename tuple<Types...>::__PairType>::Get(tupleObj);
}


}  // End namespace YSTL


#endif  // __YSTL_ACTUALTUPLE_H
