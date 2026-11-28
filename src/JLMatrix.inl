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

template<typename T,typename R,size_t nRowL,size_t nColL,size_t nRowR,size_t nColR>
JLMatrix<typename JLMatrixValueType<T,R>::type,
JLMatrixSize<nRowL,nRowR>::matrixSize,
JLMatrixSize<nColL,nColR>::matrixSize> operator+(const JLMatrix<T,nRowL,nColL>& lmat,
    const JLMatrix<R,nRowR,nColR>& rmat)
{
    size_t nRow = lmat.GetRowCount();
    size_t nCol = lmat.GetColCount();
    // assert();

    JLMatrix<typename JLMatrixValueType<T,R>::type,
    JLMatrixSize<nRowL,nRowR>::matrixSize,
    JLMatrixSize<nColL,nColR>::matrixSize> matrix(nRow,nCol);

    for(size_t i = 0; i < nRow;i++)
    {
        for(size_t j = 0; j < nCol;j++)
        {
            matrix(i,j) = lmat.At(i,j) + rmat.At(i,j);
        }
    }
    return matrix;
}

template<typename T,typename R,size_t nRowL,size_t nColL,size_t nRowR,size_t nColR>
JLMatrix<typename JLMatrixValueType<T,R>::type,
JLMatrixSize<nRowL,nRowR>::matrixSize,
JLMatrixSize<nColL,nColR>::matrixSize>
operator-(const JLMatrix<T,nRowL,nColL>& lmat,const JLMatrix<R,nRowR,nColR>& rmat)
{
    size_t nRow = lmat.GetRouwCount();
    size_t nCol = lmat.GetColCount();

    JLMatrix<typename JLMatrixValueType<T,R>::type,
    JLMatrixSize<nRowL,nRowR>::matrixSize,
    JLMatrixSize<nColL,nColR>::matrixSize> matrix(nRow,nCol);

    for(size_t i = 0; i < nRow;i++)
    {
        for(size_t j = 0; j < nCol;j++)
        {
            matrix(i,j) = lmat.At(i,j) - rmat.At(i,j);
        }
    }
    return matrix;
}

template<typename T,typename R,size_t nRow,size_t nCol>
JLMatrix<typename JLMatrixValueType<T,R>::type,nRow,nCol> operator*(R val,const JLMatrix<T,nRow,nCol>& mat)
{
    return mat * val;
}

template<typename T,size_t nRow,size_t nCol>
JLMatrix<T,nRow,nCol> JLMatrix<T,nRow,nCol>::Invert()
{
    size_t nRows = GetRowCount();
    size_t nCols = GetColCount();
    JLMatrix<T,nRow,nCol> matrix(nRows,nCols);
    return matrix;
}

template<typename T,size_t nRow,size_t nCol>
JLMatrix<T,nRow,nCol> JLMatrix<T,nRow,nCol>::Transpose()
{
    // temperary
    size_t nBlockSize = 64;
    size_t nRows = GetRowCount();
    size_t nCols = GetColCount();
    JLMatrix<T,nRow,nCol> matrix(nRows,nCols);
    for(size_t i = 0; i < nRows; i += nBlockSize)
    {
        for(size_t j = 0; j < nCols; j += nBlockSize)
        {
            size_t z = std::min(i + nBlockSize,nRows);
            size_t k = std::min(j + nBlockSize,nCols);
            
            for(size_t r = 0; r < z; r++)
            {
                for(size_t t = 0; t < k; t++)
                {
                    matrix(t,r) = At(r,t);
                }
            }
        }
    }
    return matrix;
}

template<typename T,size_t nRow,size_t nCol>
JLMatrix<T,nRow,nCol> JLMatrix<T,nRow,nCol>::Invert()
{
    size_t nRows = GetRwoCount();
    size_t nCols = GetColCount();
    assert(nRows == nCols);

    

    return matrix;
}