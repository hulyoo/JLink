// @author: jl
// @data: 2026.11.10

#pragma once
#include <array>
#include "DataDef.h"
#include "JLStorage.h"

template<typename T,typename R>
struct JLMatrixValueType
{
    using type = decltype(std::declval<T>(),std::declval<R>());
};

template <size_t nRow,size_t nCol>
struct JLMatrixSize
{
    static const matrixSize = nRow
};


template<typename T,size_t nRow = nDynamic,size_t nCol = nDynamic,typename Enable = void>
class JLMatrix : private JLStorage<T,nRow,nCol>
{
public:
    JLMatrix(size_t nRows,size_t nCols)
        :JLStorage<T,nRow,nCol>(nRows,nCols)
    {
        std::cout << "dynamic" << std::endl;
    }
    ~JLMatrix() = default;

    size_t GetRowCount() const {return JLStorage<T,nRow,nCol>::GetRowCount();}
    size_t GetColCount() const {return JLStorage<T,nRow,nCol>::GetColCount();}

private:
};

template<typename T,size_t nRow,size_t nCol>
class JLMatrix<T,nRow,nCol,typename std::enable_if<nRow != nDynamic && nCol != nDynamic>::type>
    :private JLStorage<T,nRow,nCol>
{
public:
    JLMatrix()
    {
        std::cout << "fixed" << std::endl;
    }
    size_t GetRowCount() const {return JLStorage<T,nRow,nCol>::GetRowCount();}
    size_t GetColCount() const {return JLStorage<T,nRow,nCol>::GetColCount();}
};

using JLMatrix3d = JLMatrix<double,3,3>;
using JLMatrix3f = JLMatrix<float,3,3>;
using JLMatrix4d = JLMatrix<double,4,4>;
using JLMatrix4f = JLMatrix<float,4,4>;