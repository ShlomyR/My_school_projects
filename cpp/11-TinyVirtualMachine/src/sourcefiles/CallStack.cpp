#include "../hederfiles/CallStack.hpp"

void CallStack::push(int32_t address)
{
    m_stack.push(m_ip);
    m_ip = address;
}

void CallStack::ret()
{
    m_ip = m_stack.pop();
}