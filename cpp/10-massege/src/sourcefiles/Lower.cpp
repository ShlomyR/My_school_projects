#include "Lower.hpp"



std::string Lower::translate(std::string str)
{
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::tolower(str[i]);
    }
    return str;
}
