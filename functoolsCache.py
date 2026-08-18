#!/usr/bin/env python3
# coding=UTF-8

class _Cache:

    __slots__ = ('__funcPtr', '__cacheMap')

    def __init__(this, funcPtr):

        this.__funcPtr  = funcPtr
        this.__cacheMap = {}


    def __call__(this, *args):

        if args not in this.__cacheMap:
            this.__cacheMap[args] = this.__funcPtr(*args)

        return this.__cacheMap[args]


@_Cache
def calcFib(N):

    return calcFib(N - 1) + calcFib(N - 2) if N > 1 else N


def main():

    for i in range(0xff):
        print(calcFib(i))


if __name__ == '__main__':
    main()
