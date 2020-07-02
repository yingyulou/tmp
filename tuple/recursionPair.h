/*
    recursionPair.h
    ===============
        Library recursionPair header.
*/

#ifndef __YSTL_RECURSIONPAIR_H
#define __YSTL_RECURSIONPAIR_H

namespace YSTL
{

////////////////////////////////////////////////////////////////////////////////
// Class __recursionPair (Template, Two Or More Elements Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1, typename T2>
struct __recursionPair
{
public:

    // Attribute
    T1 __first;
    T2 __second;


    // Constructor
    __recursionPair();
    __recursionPair(const T1 &first, const T2 &second);
};


////////////////////////////////////////////////////////////////////////////////
// Class __recursionPair (One Element Pair)
////////////////////////////////////////////////////////////////////////////////

template <typename T1>
struct __recursionPair<T1, void>
{
public:

    // Attribute
    T1 __first;


    // Constructor
    __recursionPair();
    explicit __recursionPair(const T1 &first);
};


}  // End namespace YSTL


#endif  // __YSTL_RECURSIONPAIR_H
