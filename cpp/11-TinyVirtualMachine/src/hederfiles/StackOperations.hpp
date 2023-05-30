#pragma once

#include "MyStack.hpp"


class StackOperations
{
public:
    StackOperations(Stack<int32_t> &stack)
    :   m_stack(stack)
    {}
    
    void dup();
    void swap();
    void inc();
    void dec();
    void print();
    void printC();
private:
    Stack<int32_t> &m_stack;
};