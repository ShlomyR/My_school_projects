// #ifndef BRAINFUCK_HPP
// #define BRAINFUCK_HPP

// #include <iostream>

// class BrainFuck
// {
// public:
//     explicit BrainFuck(size_t n);
//     explicit BrainFuck(BrainFuck const &bf);
//     BrainFuck &operator=(BrainFuck const &bf);
//     ~BrainFuck();
//     void run(const char *program);
//     void reset_memory();

// private:
//     enum class OpCode
//     {
//         NoOp = 0,
//         Right,
//         Left,
//         Increment,
//         Decrement,
//         Write,
//         Read,
//         LoopBegin,
//         LoopEnd
//     };
    
//     OpCode translate(char c);
//     void skip_forward(const char *program, size_t &i);
//     void skip_backward(const char *program, size_t &i);
//     void execute(OpCode code);

// private:
//     size_t m_capacity;
//     char *m_memory;
//     char *m_ptr;
// };

// #endif

#pragma once

#include <string>

enum class OpCode
{
    NoOp = ' ',
    Right = '>',
    Left = '<',
    Increment = '+',
    Decrement = '-',
    Write = '.',
    Read = ',',
    LoopBegin = '[',
    LoopEnd = ']'
};

class BrainFuckInterpreter
{

public:
    BrainFuckInterpreter(std::string s)
    : str(s)
    {}

    void run();

private:
    char array[30000] = {0};
    char *ptr = array;
    char current_char;
    unsigned int i, loop;
    std::string str;
    OpCode commands;

    void interpretCommand();
    
};