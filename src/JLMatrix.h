#pragma once
#include "Storage.h"


template<typename T,typename R>
struct JLMatrixValueType
{
    using valuetype = decltype(std::declval<T>() * std::declval<R>());
};

template<size_t nRow,size_t nCol>
struct JLMatrixSize
{
    static constexpr size_t size = (nRow == nDynamic || nCol == nDynamic) ? nDynamic : nRow;
};



template<typename T,size_t nRows,size_t nCols>
class JLMatrix : private JLMatrixStorage<T,nRows,nCols>
{
    using Base = JLMatrixStorage<T,nRows,nCols>;
public:

       template<size_t R = nRows, size_t C = nCols,
             typename std::enable_if<(R != nDynamic && C != nDynamic), int>::type = 0>
    JLMatrix()
    {

    };

    template<size_t R = nRows, size_t C = nCols,
             typename std::enable_if<(R == nDynamic || C == nDynamic), int>::type = 0>
    JLMatrix(size_t nRow,size_t nCol)
    {

    }
    ~JLMatrix() = default;

    size_t GetRowCount() const noexcept{return Base::GetRowCount();}
    size_t GetColCount() const noexcept{return Base::GetColCount();}

    T& operator()(size_t nRow,size_t nCol)
    {
        return Base::At(nRow,nCol);
    }

    const T& operator()(size_t nRow,size_t nCol) const
    {
        return Base::At(nRow,nCol);
    }

    void Mul(JLMatrix& out,const JLMatrix& rmat); 
    

private:
};

template<typename T,typename R,size_t nRows,size_t nPub,size_t nCols>
JLMatrix<JLMatrixValueType<T,R>,nRows,nCols> operator*(JLMatrix<T,nRows,nPub> lmat,JLMatrix<R,nPub,nCols> rmat);

using JLMatrix4f = JLMatrix<float,4,4>;
using JLMatrix4d = JLMatrix<double,4,4>;
using JLMatrix4i = JLMatrix<int,4,4>;
using JLMatrix3f = JLMatrix<float,3,3>;
using JLMatrix3d = JLMatrix<double,3,3>;
using JLMatrix3i = JLMatrix<int,3,3>;

#include "JLMatrix.inl"