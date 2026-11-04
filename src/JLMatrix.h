#pragma once
#include "Storage.h"

template<typename T,size_t nRows,size_t nCols>
class JLMatrix : private JLMatrixStorage
{
public:
    JLMatrix();
    ~JLMatrix() = default;

private:
};