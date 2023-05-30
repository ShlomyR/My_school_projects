#pragma once

#include "BinaryExpr.hpp"

class Modulo : public BinaryOp::BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override
    {
        return (int)m_right->calc() % (int)m_left->calc();
    }
};