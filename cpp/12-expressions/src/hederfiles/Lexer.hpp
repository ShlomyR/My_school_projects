#pragma once

#include <fstream>
#include <string>
#include <vector>

class Lexer
{
public:
    Lexer(std::string &);
    std::vector<std::string> doLexer();
private:
    std::ifstream m_program;
};