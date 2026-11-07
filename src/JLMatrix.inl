#pragma once
#include "JLMatrix.h"

template<typename T,size_t nRows,size_t nPub,size_t nCols>
JLMatrix<T,nRows,nCols> operator*(JLMatrix<T,nRows,nPub> lmat,JLMatrix<T,nPub,nCols> rmat)
{
    assert(GetRowCount() == matrix.GetColCount());
    return JLMatrix<double,3,3>();
}
