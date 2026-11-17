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
    static const size_t matrixSize = (nRow != nDynamic) ? nRow : nDynamic;
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

    T& operator()(size_t nRowIndx,size_t nColIndx)
    {
        return JLStorage<T,nRow,nCol>::operator()(nRowIndx,nColIndx);
    }
    
    T At(size_t nRowIndx,size_t nColIndx) {return JLStorage<T,nRow,nCol>::At(nRowIndx,nColIndx);}
    T At(size_t nRowIndx,size_t nColIndx) const {return JLStorage<T,nRow,nCol>::At(nRowIndx,nColIndx);}

private:
};



template<typename T,size_t nRow,size_t nCol>
class JLMatrix<T,nRow,nCol,typename std::enable_if<nRow != nDynamic && nCol != nDynamic>::type>
    :private JLStorage<T,nRow,nCol>
{
public:
    JLMatrix(size_t nRows = nRow,size_t nCols = nCol)
    {
        std::cout << "fixed" << std::endl;
    }
    size_t GetRowCount() const {return JLStorage<T,nRow,nCol>::GetRowCount();}
    size_t GetColCount() const {return JLStorage<T,nRow,nCol>::GetColCount();}

    T At(size_t nRowIndx,size_t nColIndx) {return JLStorage<T,nRow,nCol>::At(nRowIndx,nColIndx);}
    T At(size_t nRowIndx,size_t nColIndx) const {return JLStorage<T,nRow,nCol>::At(nRowIndx,nColIndx);}

    T& operator()(size_t nRowIndx,size_t nColIndx)
    {
        return JLStorage<T,nRow,nCol>::operator()(nRowIndx,nColIndx);
    }
};

template<typename T,typename R,size_t nRowL,size_t nColL,size_t nRowR,size_t nColR>
JLMatrix<typename JLMatrixValueType<T,R>::type,nRowL,nColR> operator*(const JLMatrix<T,nRowR,nColR>& lmat,
    const JLMatrix<R,nRowR,nColR>& rmat);

template<typename T,typename R,size_t nRow,size_t nCol>





using JLMatrix3d = JLMatrix<double,3,3>;
using JLMatrix3f = JLMatrix<float,3,3>;
using JLMatrix4d = JLMatrix<double,4,4>;
using JLMatrix4f = JLMatrix<float,4,4>;

#include "JLMatrix.inl"