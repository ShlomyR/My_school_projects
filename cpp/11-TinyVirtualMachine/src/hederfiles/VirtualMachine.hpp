#pragma once

#include <array>
#include <vector>
#include <iostream>
#include <functional>

#include "MyStack.hpp"
#include "CallStack.hpp"
#include "JumpOperations.hpp"
#include "StackOperations.hpp"
#include "ArithmeticOperations.hpp"

enum class OpCode
{
    ADD,
    SUB,
    MUL,
    DIV,
    POP,
    PUSH,
    DUP,
    SWAP,
    PRINT,
    PRINT_C,
    NOP,
    HALT,
    INC,
    DEC,
    JMP,
    JZ,
    JNZ,
    CALL,
    RET,
};

class VirtualMachine
{
public:
    VirtualMachine(std::vector<int32_t> code)
        : m_ip(0)
        , m_jump(m_stack,m_ip)
        , m_stack()
        , m_call_stack(m_stack,m_ip)
        , m_stack_op(m_stack)
        , m_code(code)
        , m_arithmetic(m_stack)
    {
        initstateArray();
    }

    void Execute();
    int32_t value();
private:
    OpCode GetNextInstruction();
    void Execute(OpCode);
    void initstateArray();
    void arrayAt(OpCode);
private:
    //Out sourcing objects
    int32_t m_ip;
    JumpOperations m_jump;
    Stack<int32_t> m_stack;
    CallStack m_call_stack;
    StackOperations m_stack_op;
    std::vector<int32_t> m_code;
    ArithmeticOperations m_arithmetic;

    std::array<std::function<void()>, 22> m_array;
};

// class VirtualMachine
// {
// public:
//     VirtualMachine(std::vector<int32_t> code)
//         : m_code(code)
//         , m_ip(0)
//     {
//         m_array[(int32_t)OpCode::ADD] = [this]() { Add(); };
//         m_array[(int32_t)OpCode::SUB] = [this]() { Sub(); };
//         m_array[(int32_t)OpCode::MUL] = [this]() { Mul(); };
//         m_array[(int32_t)OpCode::DIV] = [this]() { Div(); };
//         m_array[(int32_t)OpCode::POP] = [this]() { m_stack.pop(); };
//         m_array[(int32_t)OpCode::PUSH] = [this]() { Push(); };
//         m_array[(int32_t)OpCode::DUP] = [this]() { Dup(); };
//         m_array[(int32_t)OpCode::SWAP] = [this]() { Swap(); };
//         m_array[(int32_t)OpCode::PRINT] = [this]() { Print(); };
//         m_array[(int32_t)OpCode::PRINT_C] = [this]() { PrintC(); };
//         m_array[(int32_t)OpCode::INC] = [this]() { Inc(); };
//         m_array[(int32_t)OpCode::DEC] = [this]() { Dec(); };
//         // m_array[(int32_t)OpCode::JMP] = [this]() { Jmp(0); };
//         // m_array[(int32_t)OpCode::JZ] = [this]() { Jz(0); };
//         // m_array[(int32_t)OpCode::JNZ] = [this]() { Jnz(0); };
//     }

//     void Execute();
//     int32_t value();

// private:
//     OpCode GetNextInstruction();

//     void Execute(OpCode);
//     void arrayAt(OpCode);
//     // Stack
//     int32_t pop();
//     void Pop();
//     void Push();
//     // Ariytmics
//     void Add();
//     void Sub();
//     void Mul();
//     void Div();
//     // op's
//     void Dup();
//     void Swap();
//     // add & sub top
//     void Inc();
//     void Dec();
//     // print and pop
//     void Print();
//     void PrintC();
//     // jump to address
//     void Jmp(int);
//     void Jz(int);
//     void Jnz(int);

//     std::vector<int32_t> m_code;
//     Stack<int32_t> m_stack;
//     int32_t m_ip;
//     std::array<std::function<void()>, 14> m_array;
// };
// class Stack {
// public:
//     Stack() {}
//     void push(int32_t value);
//     int32_t pop();
//     int32_t top();
//     void dup();
//     void swap();
//     void inc();
//     void dec();
//     void print();
//     void printC();
// private:
//     std::vector<int32_t> data;
// };