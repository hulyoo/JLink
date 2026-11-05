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
    JLMatrixStorage()
        :m_vecVal(nRows * nCols)
    {
    }

    ~JLMatrixStorage() = default;

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
    std::vector<T> m_vecVal;
};

template<typename T,size_t nRows,size_t nCols>
class JLMatrixStorage <T,nRows,nCols,std::enable_if_t<(nRows != nDynamic && nCols != nDynamic)>>
{
public:
    JLMatrixStorage()
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
    std::array<T,nRows * nCols> m_arrVal;
};

