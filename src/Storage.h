#pragma once
#include <stddef.h>
#include <type_traits>
#include <array>
#include <vector>
#include <assert.h>

constexpr size_t nDynamic = -1;
template<typename T,size_t nRows = nDynamic,size_t nCols = nDynamic,class Enable = void>
class JLMatrixStorage
{
public:
    JLMatrixStorage(size_t nRow,size_t nCol)
        :m_vecVal(nRow * nCol)
        ,m_nRow(nRow)
        ,m_nCol(nCol)
    {
    }

    ~JLMatrixStorage() = default;

    void Resize(size_t nRow,size_t nCol);

    T& At(size_t nRow,size_t nCol) 
    {
        assert(nRow * nCol <= m_vecVal.size());
        return m_vecVal[nRow * nCol - 1];
    }
    const T At(size_t nRow,size_t nCol) const
    {
        assert(nRow * nCol <= m_vecVal.size());
        return m_vecVal[nRow * nCol - 1];
    }

private:
    size_t m_nRow;
    size_t m_nCol;
    std::vector<T> m_vecVal;
};

template<typename T,size_t nRows,size_t nCols>
class JLMatrixStorage <T,nRows,nCols,std::enable_if_t<(nRows != nDynamic && nCols != nDynamic)>>
{
public:
    JLMatrixStorage()
        :m_nRow(nRows)
        ,m_nCol(nCols)
    {
    }
    ~JLMatrixStorage() = default;


    T& At(size_t nRow,size_t nCol)
    {
        assert(nRow * nCol <= m_arrVal.size());
        return m_arrVal[nRow * nCol - 1];
    }
    const T At(size_t nRow,size_t nCol) const
    {
        assert(nRow * nCol <= m_arrVal.size());
        return m_arrVal[nRow * nCol - 1];
    }
private:
    size_t m_nRow;
    size_t m_nCol;
    std::array<T,nRows * nCols> m_arrVal;
};

