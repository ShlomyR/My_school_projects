#pragma once

#include <iostream>

#include "Expression.hxx"

class NumberExpr : public Expression
{
public:
    NumberExpr(double val)
    : m_value(val)
    {}

    double calc() const override
    {
        return m_value;
    }
    void print(double ) const override
    {
        std::cout << "The number is: " << m_value << "\n";
    }

private:
    double m_value;
};