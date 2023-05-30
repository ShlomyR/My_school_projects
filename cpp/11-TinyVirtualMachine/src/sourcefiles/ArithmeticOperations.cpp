#include "../hederfiles/ArithmeticOperations.hpp"

void ArithmeticOperations::Add()
{
    int32_t value1 = m_stack.pop();
    int32_t value2 = m_stack.pop();
    m_stack.push(value1 + value2);
}

void ArithmeticOperations::Sub()
{
    int32_t value1 = m_stack.pop();
    int32_t value2 = m_stack.pop();
    m_stack.push(value1 - value2);
}

void ArithmeticOperations::Mul()
{
    int32_t value1 = m_stack.pop();
    int32_t value2 = m_stack.pop();
    m_stack.push(value1 * value2);
}

void ArithmeticOperations::Div()
{
    int32_t value1 = m_stack.pop();
    int32_t value2 = m_stack.pop();
    m_stack.push(value1 / value2);
}