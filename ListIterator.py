#!/usr/bin/env python3
# coding=UTF-8

################################################################################
# Class MyList
################################################################################

class MyList:

    __slots__ = ('__listObj',)

    def __init__(self, __listObj):

        self.__listObj = __listObj


    def __iter__(self):

        return _MyListIterator(self.__listObj)


################################################################################
# Class _MyListIterator
################################################################################

class _MyListIterator:

    __slots__ = ('__listObj', '__nowIdx', '__topIdx')

    def __init__(self, __listObj):

        self.__listObj = __listObj
        self.__nowIdx  = 0
        self.__topIdx  = len(__listObj)


    def __next__(self):

        if self.__nowIdx == self.__topIdx:
            raise StopIteration

        self.__nowIdx += 1

        return self.__listObj[self.__nowIdx - 1]


################################################################################
# Main Paogram Define
################################################################################

def main():

    for i in MyList([1, 2, 3]):
        print(i)


if __name__ == '__main__':
    main()
