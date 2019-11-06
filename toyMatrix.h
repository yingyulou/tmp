/*
    A toy 2D Matrix.
*/

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <utility>

#ifndef __TOYMATRIX_INCLUDED_H
#define __TOYMATRIX_INCLUDED_H

namespace ToyMatrix
{

template <typename __T>
class Matrix
{
public:

    Matrix(): __rowNum(0), __colNum(0), __matrixPtr(nullptr) {};


    explicit Matrix(int rowNum, int colNum): __rowNum(rowNum), __colNum(colNum),
        __matrixPtr(__allocateMatrix(rowNum, colNum)) {}


    Matrix(const Matrix &otherMatrix): __rowNum(otherMatrix.__rowNum), __colNum(otherMatrix.__colNum),
        __matrixPtr(__allocateMatrix(__rowNum, __colNum)) {}


    Matrix(Matrix &&otherMatrix): __rowNum(otherMatrix.__rowNum), __colNum(otherMatrix.__colNum),
        __matrixPtr(__allocateMatrix(__rowNum, __colNum)) {}


    Matrix &operator=(const Matrix &otherMatrix)
    {
        __deallocateMatrix();

        __rowNum    = otherMatrix.__rowNum;
        __colNum    = otherMatrix.__colNum;
        __matrixPtr = __allocateMatrix(__rowNum, __colNum);

        return *this;
    }


    Matrix &operator=(Matrix &&otherMatrix)
    {
        __deallocateMatrix();

        __rowNum    = otherMatrix.__rowNum;
        __colNum    = otherMatrix.__colNum;
        __matrixPtr = __allocateMatrix(__rowNum, __colNum);

        return *this;
    }


    __T *operator[](int rowIdx)
    {
        return __matrixPtr + __colNum * rowIdx;
    }


    __T *at(int rowIdx)
    {
        if (rowIdx >= __rowNum) throw std::out_of_range("Matrix index out of range!");
        else return operator[](rowIdx);
    }


    const __T *operator[](int rowIdx) const
    {
        return const_cast<Matrix<__T> *>(this)->operator[](rowIdx);
    }


    const __T *at(int rowIdx) const
    {
        return const_cast<Matrix<__T> *>(this)->at(rowIdx);
    }


    int row() const { return __rowNum; }


    int col() const { return __colNum; }


    std::pair<int, int> shape() const { return {__rowNum, __colNum}; }


    ~Matrix() { __deallocateMatrix(); }


private:

    int __rowNum, __colNum;
    __T *__matrixPtr;


    __T *__allocateMatrix(int rowNum, int colNum)
    {
        return static_cast<__T *>(malloc(sizeof(__T) * rowNum * colNum));
    }


    void __deallocateMatrix()
    {
        free(__matrixPtr);
    }


template <typename __V>
friend std::ostream &operator<<(std::ostream &os, const Matrix<__V> &matrixObj);
};


template <typename __V>
std::ostream &operator<< (std::ostream &os, const Matrix<__V> &matrixObj)
{
    for (int rowIdx = 0; rowIdx < matrixObj.__rowNum; rowIdx++)
    {
        for (int colIdx = 0; colIdx < matrixObj.__colNum - 1; colIdx++)
        {
            os << matrixObj[rowIdx][colIdx] << ' ';
        }

        os << matrixObj[rowIdx][matrixObj.__colNum - 1] << std::endl;
    }

    return os;
}


}  // End namespace ToyMatrix


#endif  // __TOYMATRIX_INCLUDED_H