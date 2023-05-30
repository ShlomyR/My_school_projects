#include "../hederfiles/VirtualMachine.hpp"
#include "VirtualMachine.hpp"
// #include "VirtualMachine.hpp"

void VirtualMachine::Execute()
{
    //Phase one
    // while (true) {
    //     OpCode op = GetNextInstruction();
    //     if (op == OpCode::HALT) {
    //         break;
    //     }
    //     Execute(op);
    // }

    //Phase two 
    while (true) {
        OpCode op = GetNextInstruction();
        if (op == OpCode::HALT) {
            break;
        }
        arrayAt(op);
    }
}

int32_t VirtualMachine::value()
{
    if (m_stack.is_empty()) {
       std::cerr << "The Stack is empty!!! ";
       return 0;
    }
    
    return m_stack.top();
}

OpCode VirtualMachine::GetNextInstruction()
{
    return static_cast<OpCode>(m_code[m_ip++]);
}

void VirtualMachine::arrayAt(OpCode op)
{
    m_array[(int32_t)op]();
}

void VirtualMachine::initstateArray()
{
    m_array[(int32_t)OpCode::ADD] = [this]() { m_arithmetic.Add(); };
    m_array[(int32_t)OpCode::SUB] = [this]() { m_arithmetic.Sub(); };
    m_array[(int32_t)OpCode::MUL] = [this]() { m_arithmetic.Mul(); };
    m_array[(int32_t)OpCode::DIV] = [this]() { m_arithmetic.Div(); };
    m_array[(int32_t)OpCode::POP] = [this]() { m_stack.pop(); };
    m_array[(int32_t)OpCode::PUSH] = [this]() { m_stack.push(m_code[m_ip++]); };
    m_array[(int32_t)OpCode::DUP] = [this]() { m_stack_op.dup(); };
    m_array[(int32_t)OpCode::SWAP] = [this]() { m_stack_op.swap(); };
    m_array[(int32_t)OpCode::PRINT] = [this]() { m_stack_op.print(); };
    m_array[(int32_t)OpCode::PRINT_C] = [this]() { m_stack_op.printC(); };
    m_array[(int32_t)OpCode::INC] = [this]() { m_stack_op.inc(); };
    m_array[(int32_t)OpCode::DEC] = [this]() { m_stack_op.dec(); };
    m_array[(int32_t)OpCode::JMP] = [this]() { m_jump.Jmp(m_code[m_ip++]); };
    m_array[(int32_t)OpCode::JZ] = [this]() { m_jump.Jz(m_code[m_ip++]); };
    m_array[(int32_t)OpCode::JNZ] = [this]() { m_jump.Jnz(m_code[m_ip++]); };
    m_array[(int32_t)OpCode::CALL] = [this]() { m_call_stack.push(m_code[m_ip++]); };
    m_array[(int32_t)OpCode::RET] = [this]() { m_call_stack.ret(); };
    m_array[(int32_t)OpCode::NOP] = [this]() {  };
    m_array[(int32_t)OpCode::HALT] = [this]() { return; };
}

void VirtualMachine::Execute(OpCode op)
{
    switch (op) {
        case OpCode::ADD:
            m_arithmetic.Add();
            break;
        case OpCode::SUB:
            m_arithmetic.Sub();
            break;
        case OpCode::MUL:
            m_arithmetic.Mul();
            break;
        case OpCode::DIV:
            m_arithmetic.Div();
            break;
        case OpCode::POP:
            m_stack.pop();
            break;
        case OpCode::PUSH:
            m_stack.push(m_code[m_ip++]);
            break;
        case OpCode::DUP:
            m_stack_op.dup();
            break;
        case OpCode::SWAP:
            m_stack_op.swap();
            break;
        case OpCode::PRINT:
            m_stack_op.print();
            break;
        case OpCode::PRINT_C:
            m_stack_op.printC();
            break;
        case OpCode::NOP:
            break;
        case OpCode::HALT:
            return;
        case OpCode::INC:
            m_stack_op.inc();
            break;
        case OpCode::DEC:
            m_stack_op.dec();
            break;
        case OpCode::JMP:
            m_jump.Jmp(m_code[m_ip++]);
            break;
        case OpCode::JZ:
            m_jump.Jz(m_code[m_ip++]);
            break;
        case OpCode::JNZ:
            m_jump.Jnz(m_code[m_ip++]);
            break;
        default:
            std::cerr << "Invalid opcode: " << static_cast<int32_t>(op) << std::endl;
            //throw std::runtime_error("Invalid opcode");
    }
}