#pragma once
#include <stddef.h>
#include <vector>
#include <array>


#include "DataDef.h"


template<typename T,size_t nRow,size_t nCol,typename Enable = void>
class JLStorage
{
public:
    JLStorage(size_t nRows,size_t nCols)
        :m_nRow(nRows)
        ,m_nCol(nCols)
        ,m_vecVal()
    {
        std::cout<< "dynamic storage" << std::endl;
    }

    ~JLStorage() = default;

    size_t GetRowCount() const {return m_nRow;} 
    size_t GetColCount() const {return m_nRow;}

    T At(size_t nRowIndx,size_t nColIndx){return m_vecVal[nRowIndx * m_nCol + nColIndx];}

    T& operator()(size_t nRowIndx,size_t nColIndx)
    {
        return m_vecVal[nRowIndx * m_nRow + nColIndx];
    }

private:
    size_t m_nRow;
    size_t m_nCol;
    std::vector<T> m_vecVal;
};


template<typename T,size_t nRow,size_t nCol>
class JLStorage<T,nRow,nCol,typename std::enable_if<nRow != nDynamic && nCol != nDynamic>::type>
{
public:
    JLStorage()
    {
        std::cout << "fixed storage" << std::endl;
    }
    ~JLStorage() = default;

    size_t GetRowCount() const {return nRow;}
    size_t GetColCount() const {return nCol;}

    T At(size_t nRowIndx,size_t nColIndx){return m_arrVal[nRowIndx * nCol + nColIndx];}

    T& operator()(size_t nRowIndx,size_t nColIndx)
    {
        return m_arrVal[nRowIndx * nCol + nColIndx];
    }

private:
    std::array<T,nRow * nCol> m_arrVal;
};