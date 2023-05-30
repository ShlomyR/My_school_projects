#pragma once

class Expression
{
public:
    Expression() = default;
    virtual ~Expression() = default;
    
    Expression(Expression const&) = delete;
    Expression& operator=(Expression const&) = delete;
    
    virtual double calc() const = 0;
    virtual void print(double ) const = 0;
};