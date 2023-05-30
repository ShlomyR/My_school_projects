#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "Expression.hxx"

class Parser
{
public:
    void buildTree(std::string const &);
    std::unique_ptr<Expression> parse(std::string const &);
public:
    static std::string::size_type getIndex();
    static void incrementIndex();
    void resetIndex();
private:
    static std::string::size_type m_index;
};