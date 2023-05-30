#pragma once

#include <string>
#include <vector>
#include "MyStack.hpp"

class Rpn
{
public:
    Rpn(std::vector<std::string> &vec)
    :   m_vec(vec)
    ,   m_stack()
    {}

    int prec(char c);
    std::vector<std::string> infixToPostfix();
private:
    std::vector<std::string> &m_vec;
    Stack<char> m_stack;
};