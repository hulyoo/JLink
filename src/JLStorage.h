#pragma once
#include <stddef.h>
#include <vector>
#include <array>


#include "DataDef.h"

template<typename T,size_t nRow,size_t nCol,typename Enable = void>
class JLStorage
{
public:
    JLStorage()
        :m_vecVal(){std::cout<< "dynamic storage" << std::endl;}
    ~JLStorage() = default;
private:
    std::vector<T> m_vecVal;
};

template<typename T,size_t nRow,size_t nCol>
class JLStorage<T,nRow,nCol,typename std::enable_if<nRow != nDynamic && nCol != nDynamic>::type>
{
public:
    JLStorage(){std::cout << "fixed storage" << std::endl;}
private:
    std::array<T,nRow * nCol> m_arrVal;
};