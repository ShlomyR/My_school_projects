#pragma once

#include "MyStack.hpp"

class JumpOperations
{
public:
    JumpOperations(Stack<int32_t> &stack,int32_t &ip)
        : m_stack(stack)
        , m_ip(ip)
    {}

    void Jmp(int address);
    void Jz(int address);
    void Jnz(int address);

private:
    Stack<int32_t> &m_stack;
    int32_t &m_ip;
};