#pragma once
#include <stddef.h>
#include <array>

constexpr size_t nDynamic = 0;

template<typename T,size_t nRow = nDynamic,size_t nCol = nDynamic,typename Enable = void>
class JLMatrix
{
public:
    JLMatrix()
    {
        std::cout << "dynamic" << std::endl;
    }
    ~JLMatrix() = default;


private:
};

template<typename T,size_t nRow,size_t nCol>
class JLMatrix<T,nRow,nCol,typename std::enable_if<nRow != nDynamic && nCol != nDynamic>::type>
{
public:
    JLMatrix()
    {
        std::cout << "fixed" << std::endl;
    }
};

using JLMatrix3d = JLMatrix<double,3,3>;
using JLMatrix3f = JLMatrix<float,3,3>;
using JLMatrix4d = JLMatrix<double,4,4>;
using JLMatrix4f = JLMatrix<float,4,4>;