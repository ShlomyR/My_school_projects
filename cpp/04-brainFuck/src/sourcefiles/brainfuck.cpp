#include <iostream>
#include <stdio.h>

#include "brainfuck.hpp"

void BrainFuckInterpreter::run() {
    interpretCommand();
}

void BrainFuckInterpreter::interpretCommand()
{
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '>') {
            commands = OpCode::Right;
        } else if (str[i] == '<') {
            commands = OpCode::Left;
        } else if (str[i] == '+') {
            commands = OpCode::Increment;
        } else if (str[i] == '-') {
            commands = OpCode::Decrement;
        } else if (str[i] == '.') {
            commands = OpCode::Write;
        } else if (str[i] == ',') {
            commands = OpCode::Read;
        } else if (str[i] == '[') {
            commands = OpCode::LoopBegin;
        } else if (str[i] == ']') {
            commands = OpCode::LoopEnd;
        } else if (str[i] == ' ') {
            commands = OpCode::NoOp;
        }
        switch (commands)
        {
        case OpCode::Right:
            ++ptr;
            break;
        case OpCode::Left:
            --ptr;
            break;
        case OpCode::Increment:
            ++(*ptr);
            break;
        case OpCode::Decrement:
            --(*ptr);
            break;
        case OpCode::Write:
            putchar(*ptr);
            break;
        case OpCode::Read:
            *ptr = getchar();
            break;
        case OpCode::LoopBegin:
            if (*ptr == 0) {
                loop = 1;
                while (loop > 0) {
                    current_char = str[++i];

                    if (current_char == '[') {
                        loop++;
                    } else if (current_char == ']') {
                        loop--;
                    }
                }
            }
            break;
        case OpCode::LoopEnd:
            if (*ptr) {
                loop = 1;
                while (loop > 0) {
                    current_char = str[--i];

                    if (current_char == '[') {
                        loop--;
                    } else if (current_char == ']') {
                        loop++;
                    }
                }
            }
            break;
        case OpCode::NoOp:

            break;
        };
    }
}

// #include <iostream>
// #include <cstdlib>
// #include <cstring>

// BrainFuck::BrainFuck(size_t n)
//     :   m_capacity(n),
//         m_memory(new char[n]),
//         m_ptr(m_memory)
// {
//     reset_memory();
// }

// BrainFuck::BrainFuck(BrainFuck const &bf)
//     :   m_capacity(bf.m_capacity),
//         m_memory(new char[bf.m_capacity]),
//         m_ptr(m_memory + (bf.m_ptr - bf.m_memory))
// {
//     std::memcpy(m_memory, bf.m_memory, m_capacity);
// }

// BrainFuck &BrainFuck::operator=(BrainFuck const &bf)
// {
//     if (this != &bf)
//     {
//         delete[] m_memory;
//         m_capacity = bf.m_capacity;
//         m_memory = new char[m_capacity];
//         m_ptr = m_memory + (bf.m_ptr - bf.m_memory);
//         std::memcpy(m_memory, bf.m_memory, m_capacity);
//     }
//     return *this;
// }

// BrainFuck::~BrainFuck()
// {
//     delete[] m_memory;
// }

// void BrainFuck::run(const char *program)
// {
//     for (size_t i = 0; program[i]; i++) {
//         execute(translate(program[i]));
//     }
// }

// void BrainFuck::reset_memory()
// {
//     std::memset(m_memory, 0, m_capacity);
// }

// BrainFuck::OpCode BrainFuck::translate(char c)
// {
//     switch (c)
//     {
//     case '>':
//         return OpCode::Right;
//     case '<':
//         return OpCode::Left;
//     case '+':
//         return OpCode::Increment;
//     case '-':
//         return OpCode::Decrement;
//     case '.':
//         return OpCode::Write;
//     case ',':
//         return OpCode::Read;
//     case '[':
//         return OpCode::LoopBegin;
//     case ']':
//         return OpCode::LoopEnd;
//     default:
//         return OpCode::NoOp;
//     }
// }

// void BrainFuck::skip_forward(const char *program, size_t &i)
// {
//     size_t depth = 1;
//     while (program[++i] && depth) {
//         if (program[i] == '[') {
//             ++depth;
//         } else if (program[i] == ']') {
//             --depth;
//         }
//     }
// }

// void BrainFuck::skip_backward(const char *program, size_t &i)
// {
//     size_t depth = 1;
//     while (i-- && depth) {
//         if (program[i] == '[') {
//             --depth;
//         } else if (program[i] == ']') {
//             ++depth;
//         }
//     }
// }

// void BrainFuck::execute(OpCode code)
// {
//     switch (code)
//     {
//     case OpCode::Right:
//         ++m_ptr;
//         break;
//     case OpCode::Left:
//         --m_ptr;
//         break;
//     case OpCode::Increment:
//         ++(*m_ptr);
//         break;
//     case OpCode::Decrement:
//         --(*m_ptr);
//         break;
//     case OpCode::Write:
//         putchar(*m_ptr);
//         break;
//     case OpCode::Read:
//         *m_ptr = getchar();
//         break;
//     case OpCode::LoopBegin:
//         if (!*m_ptr) {
//             skip_forward(program, i);
//         }
//         break;
//     case OpCode::LoopEnd:
//         if (*m_ptr) {
//             skip_backward(program, i);
//         }
//         break;
//     case OpCode::NoOp:
//     default:
//         break;
//     }
// }

// void BrainFuck::run(const char *program)
// {
//     reset_memory();
//     for (size_t i = 0; program[i]; ++i) {
//         OpCode code = translate(program[i]);
//         execute(code);
//     }
// }

// void BrainFuck::reset_memory()
// {
//     std::memset(m_memory, 0, m_capacity);
//     m_ptr = m_memory;
// }

// // BrainFuck::OpCode BrainFuck::translate(char c)
// // {
// //     switch (c)
// //     {
// //     case '>':
// //         return OpCode::Right;
// //     case '<':
// //         return OpCode::Left;
// //     case '+':
// //         return OpCode::Increment;
// //     case '-':
// //         return OpCode::Decrement;
// //     case '.':
// //         return OpCode::Write;
// //     case ',':
// //         return OpCode::Read;
// //     case '[':
// //         return OpCode::LoopBegin;
// //     case ']':
// //         return OpCode::LoopEnd;
// //     default:
// //         return OpCode::NoOp;
// //     }
// // }


// int main()
// {


//     return 0;
// }