#pragma once

#include "MyStack.hpp"

class ArithmeticOperations
{
public:
    ArithmeticOperations(Stack<int32_t> &stack)
        : m_stack(stack)
    {}

    void Add();
    void Sub();
    void Mul();
    void Div();

private:
    Stack<int32_t> &m_stack;
};