#include "../hederfiles/StackOperations.hpp"


void StackOperations::dup() 
{
    int32_t value = m_stack.top();
    m_stack.push(value);
}


void StackOperations::swap() 
{
    int32_t value1 = m_stack.pop();
    int32_t value2 = m_stack.pop();
    m_stack.push(value1);
    m_stack.push(value2);
}

void StackOperations::inc() 
{
    int32_t value = m_stack.pop();
    ++value;
    m_stack.push(value);
}

void StackOperations::dec() 
{
    int32_t value = m_stack.pop();
    --value;
    m_stack.push(value);
}

void StackOperations::print() 
{
    int32_t value = m_stack.pop();
    std::cout << value << std::endl;
}

void StackOperations::printC() 
{
    int32_t value = m_stack.pop();
    std::cout << static_cast<char>(value) << std::endl;
}
