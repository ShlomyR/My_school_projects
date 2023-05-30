#pragma once

#include "BinaryExpr.hpp"

class Multiply : public BinaryOp::BinaryExpr
{
public:
    double calc() const override
    {
        return m_left->calc() * m_right->calc();
    }

    // void print(double val) const override
    // {
    //     std::cout << val << "\n";
    // }
};