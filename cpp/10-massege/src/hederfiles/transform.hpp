#pragma once

#include <string>

class transform
{
public:
    virtual std::string translate(std::string) = 0;
    virtual ~transform() = default;
};