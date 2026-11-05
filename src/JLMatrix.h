#pragma once
#include "Storage.h"

template<typename T,size_t nRows,size_t nCols>
class JLMatrix : private JLMatrixStorage<T,nRows,nCols>
{
    using Base = JLMatrixStorage<T,nRows,nCols>;
public:
    JLMatrix(){};
    ~JLMatrix() = default;

    T& operator()(size_t nRow,size_t nCol)
    {
        return Base::At(nRow,nCol);
    }

    const T& operator()(size_t nRow,size_t nCol) const
    {
        return Base::At(nRow,nCol);
    }

    JLMatrix& operator*(JLMatrix matrix)
    {

    } 
    

private:
};

using JLMatrix4f = JLMatrix<float,4,4>;
using JLMatrix4d = JLMatrix<double,4,4>;
using JLMatrix4i = JLMatrix<int,4,4>;
using JLMatrix3f = JLMatrix<float,3,3>;
using JLMatrix3d = JLMatrix<double,3,3>;
using JLMatrix3i = JLMatrix<int,3,3>;

#include "JLMatrix.inl"