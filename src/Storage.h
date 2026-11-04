#pragma once
#include <stddef.h>
#include <type_traits>
#include <array>

constexpr int nDynamic = -1;
template<typename T,size_t nRows,size_t nCols,class Enable = void>
class JLMatrixStorage
{
public:
    JLMatrixStorage();
    ~JLMatrixStorage() = default;

    T At(int nRow,int nCol) const noexcept;
    const T At(int nRow,int nCol) const noexcept;
private:
    std::vector<T> m_vecVal;
};

template<typename T,size_t nRows,size_t nCols>
class JLMatrixStorage <T,nRows,nCols,std::enable_if_t<(nRows != nDynamic && nCols != nDynamic)>>
{
public:
    JLMatrixStorage();
    ~JLMatrixStorage() = default;

    T At(int nRow,int nCol) const noexcept;
    const T At(int nRow,int nCol) const noexcept;
private:
    std::array<T,nRows * nCols> m_arrVal;
};

