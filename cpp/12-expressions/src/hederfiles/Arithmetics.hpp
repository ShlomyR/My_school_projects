#pragma once

#include "NumberExpr.hpp"
#include "BinaryExpr.hpp"

#include <cmath>

namespace ArithmeticOp
{

class PlusExpr : public BinaryOp::BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override
    {
        return m_right->calc() + m_left->calc();
    }
};

class MinExpr : public BinaryOp::BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override
    {
        return m_right->calc() - m_left->calc();
    }
};

class MulExpr : public BinaryOp::BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override
    {
        return m_right->calc() * m_left->calc();
    }
};

class DivExpr : public BinaryOp::BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override
    {
        return m_right->calc() / m_left->calc();
    }
};

class PowerExpr : public BinaryOp::BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override
    {
        return pow(m_right->calc(), m_left->calc());
    }
};

class ModuloExpr : public BinaryOp::BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override
    {
        return (int)m_right->calc() % (int)m_left->calc();
    }
};

} // namespace ArithmeticOp