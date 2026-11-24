// @author: jl
// @data: 2026.11.10

#pragma once
#include <array>
#include "DataDef.h"
#include "JLStorage.h"

template<typename T,typename R>
struct JLMatrixValueType
{
    using type = std::common_type_t<std::decay_t<T>,std::decay_t<R>>;
};

template <size_t nRow,size_t nCol>
struct JLMatrixSize
{
    static const size_t matrixSize = (nRow != nDynamic && nCol != nDynamic) ? nRow : nDynamic;
};


template<typename T,size_t nRow = nDynamic,size_t nCol = nDynamic>
class JLMatrix
    :private JLStorage<T,nRow,nCol>
{
public:
    JLMatrix(size_t nRows = nRow,size_t nCols = nCol)
        :JLStorage<T,nRow,nCol>(nRows,nCols)
    {
    }
    size_t GetRowCount() const {return JLStorage<T,nRow,nCol>::GetRowCount();}
    size_t GetColCount() const {return JLStorage<T,nRow,nCol>::GetColCount();}

    T At(size_t nRowIndx,size_t nColIndx) {return JLStorage<T,nRow,nCol>::At(nRowIndx,nColIndx);}
    T At(size_t nRowIndx,size_t nColIndx) const {return JLStorage<T,nRow,nCol>::At(nRowIndx,nColIndx);}


    T& operator()(size_t nRowIndx,size_t nColIndx)
    {
        return JLStorage<T,nRow,nCol>::operator()(nRowIndx,nColIndx);
    }

    template<typename R,
    typename = typename std::enable_if<std::is_arithmetic<R>::value>::type>
    JLMatrix<typename JLMatrixValueType<T,R>::type,nRow,nCol> operator*(R value) const
    {
        size_t nRowCount = GetRowCount();
        size_t nColCount = GetColCount();
        JLMatrix<typename JLMatrixValueType<T,R>::type,nRow,nCol> matrix(nRowCount,nColCount);
        for(size_t i = 0; i < nRowCount; i++)
        {
            for(size_t j = 0; j < nColCount; j++)
            {
                matrix(i,j) = At(i,j) * value;
            }
        }
        return matrix;
    }

    JLMatrix<T,nRow,nCol> Invert();

    JLMatrix<T,nRow,nCol> Transpose();
};


template<typename T,typename R,size_t nRowL,size_t nColL,size_t nRowR,size_t nColR>
JLMatrix<typename JLMatrixValueType<T,R>::type,
JLMatrixSize<nRowL,nRowR>::matrixSize,
JLMatrixSize<nColL,nColR>::matrixSize> 
operator+(const JLMatrix<T,nRowL,nColL>& lmat,
    const JLMatrix<R,nRowR,nColR>& rmat);

template<typename T,typename R,size_t nRowL,size_t nColL,size_t nRowR,size_t nColR>
JLMatrix<typename JLMatrixValueType<T,R>::type,
JLMatrixSize<nRowL,nRowR>::matrixSize,
JLMatrixSize<nColL,nColR>::matrixSize> 
operator-(const JLMatrix<T,nRowL,nColL>& lmat,
    const JLMatrix<R,nRowR,nColR>& rmat);

template<typename T,typename R,size_t nRowL,size_t nColL,size_t nRowR,size_t nColR>
JLMatrix<typename JLMatrixValueType<T,R>::type,nRowL,nColR> operator*(const JLMatrix<T,nRowR,nColR>& lmat,
    const JLMatrix<R,nRowR,nColR>& rmat);

template<typename T,typename R,size_t nRow,size_t nCol>
JLMatrix<typename JLMatrixValueType<T,R>::type,nRow,nCol> operator*(R val,const JLMatrix<T,nRow,nCol>& mat);


using JLMatrix3d = JLMatrix<double,3,3>;
using JLMatrix3f = JLMatrix<float,3,3>;
using JLMatrix4d = JLMatrix<double,4,4>;
using JLMatrix4f = JLMatrix<float,4,4>;

#include "JLMatrix.inl"