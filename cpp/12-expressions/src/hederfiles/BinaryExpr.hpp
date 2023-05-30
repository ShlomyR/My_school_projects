#pragma once

#include "Expression.hxx"

#include <iostream>
#include <memory>


namespace BinaryOp
{

class BinaryExpr : public Expression
{
public:
    BinaryExpr(std::unique_ptr<Expression> left
    , std::unique_ptr<Expression> right
    )
    : m_left(std::move(left))
    , m_right(std::move(right))
    {}
    
    double calc() const = 0;

    void print(double val) const override
    {
        std::cout << val << "\n";
    }
protected:
    std::unique_ptr<Expression> m_left;
    std::unique_ptr<Expression> m_right;
};

} // namespace BinaryOp