#pragma once

#include "Matrix_1.hpp"

namespace mt
{
    
double &Matrix::operator()(int i, int j)
{
    return m_vec[i][j];
}

double Matrix::operator()(int i, int j) const
{
    return m_vec[i][j];
}

int Matrix::getSize() const
{
    return m_size;
}

std::vector<std::vector<double>> Matrix::getVec() const
{
    return m_vec;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    Matrix result(m1.getSize());
    for (int i = 0; i < m1.getSize(); ++i) {
        for (int j = 0; j < m1.getSize(); ++j) {
            result(i, j) = m1.getVec()[i][j] + m2.getVec()[i][j];
        }
    }
    return result;
}

} // namespace mt