#pragma once
#include "JLMatrix.h"

template<typename T,typename R,size_t nRowL,size_t nColL,size_t nRowR,size_t nColR>
JLMatrix<typename JLMatrixValueType<T,R>::type,nRowL,nColR> operator*(const JLMatrix<T,nRowL,nColL>& lmat,
    const JLMatrix<R,nRowR,nColR>& rmat)
{
    size_t nRow = lmat.GetRowCount();
    size_t nCol = rmat.GetColCount();
    JLMatrix<typename JLMatrixValueType<T,R>::type,nRowL,nColR> matrix(nRow,nCol);
    for(size_t i = 0; i < matrix.GetRowCount();i++)
    {
        for(size_t j = 0; j < matrix.GetColCount();j++)
        {
            typename JLMatrixValueType<T,R>::type num = 0;
            for(size_t k = 0; k  < lmat.GetColCount();k++) 
            {
                num += (lmat.At(i,k) * rmat.At(k,j));
            }
            matrix(i,j) = num;
        }
    }
    return matrix;
}

