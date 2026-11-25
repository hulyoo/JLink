#pragma once
#include <iostream>

#include "JLMatrix.h"

// temperarily
template<typename T,size_t nRow,size_t nCol>
void Print(const JLMatrix<T,nRow,nCol>& mat)
{
    size_t nRows = mat.GetRowCount();
    size_t nCols = mat.GetColCount();

    for(size_t i = 0; i < nRows; i++)
    {
        for(size_t j = 0; j < nCols; j++)
        {
            std::cout << mat.At(i,j) << " ";
        }
        std::cout << std::endl;
    }
}

