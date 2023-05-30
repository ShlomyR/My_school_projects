#pragma once

#include "MyStack.hpp"

class CallStack
{
public:
    CallStack(Stack<int32_t> stack,int32_t &ip)
    :   m_stack(stack)
    ,   m_ip(ip)
    {}
    void push(int32_t);
    void ret();
private:
    Stack<int32_t> m_stack;
    int32_t &m_ip;
};