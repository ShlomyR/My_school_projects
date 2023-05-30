#include <stdio.h>
#include <algorithm>

#include "Matrix.hpp"

Matrix::Matrix()
: m_data()
, m_rows()
, m_cols()
, m_init()
{}

Matrix::Matrix(int r,int c)
: m_data(new int[r*c])
, m_rows(r)
, m_cols(c)
, m_init(r*c)
{}

Matrix::Matrix(int rows,int cols,double init)
: m_data(new int[rows*cols])
, m_rows(rows)
, m_cols(cols)
, m_init(init)
{
    
   for(int i=0;i<rows*cols;i++)
   {
       m_data[i] = init;    
   }
    
}

const int& Matrix::at(int i,int j) const
{
    return m_data[i * m_cols + j];
}

int& Matrix::at(int i,int j)
{
    return m_data[i * m_cols + j];
}

const int& Matrix::operator[](int i) const
{
    return m_data[i];
}

int& Matrix::operator[](int i)
{
    return m_data[i];
}

Matrix Matrix::operator+(const Matrix& obj)
{
    Matrix temp;
    for(int i = 0;i < temp.m_rows*temp.m_cols; i++)
    {
       temp.m_data[i] = m_data[i] + obj.m_data[i];    
    }
    return temp;
}

int Matrix::count(double x)
{
    for(int i=0;i<m_rows*m_cols;i++) {
        if(m_data[i] == x) {
            m_count++;
        } 
    }
    if (m_count == 0)
    {
        std::cout << "the number of times of- " << x << " that is fond is: " << m_count << "\n";
        return m_count;
    }
    std::cout << "the number of times of- " << x << " that is fond is: " << m_count << "\n";
    return m_count;
}