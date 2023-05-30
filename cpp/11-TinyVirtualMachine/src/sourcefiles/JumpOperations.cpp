#include "../hederfiles/JumpOperations.hpp"


void JumpOperations::Jmp(int address)
{
    // Implement jumping to the specified address
    m_ip = address;
}

void JumpOperations::Jz(int address)
{
    // Implement jumping to the specified address if the top value on the stack is zero
    if (m_stack.is_empty()) {
        return;
    }

    int32_t top = m_stack.pop();
    if (top == 0) {
        // Implement jumping to the specified address
        m_ip = address;
    }
}

void JumpOperations::Jnz(int address)
{
    // Implement jumping to the specified address if the top value on the stack is not zero
    if (m_stack.is_empty()) {
        return;
    }

    int32_t top = m_stack.pop();
    if (top != 0) {
        // Implement jumping to the specified address
        m_ip = address;
    }
}