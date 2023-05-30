#pragma once

#include <cmath>

#include "BinaryExpr.hpp"

class Power : public BinaryOp::BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override
    {
        return pow(m_right->calc(), m_left->calc());
    }
};