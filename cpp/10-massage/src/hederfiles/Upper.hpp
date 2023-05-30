#pragma once

#include "transform.hpp"

class Upper : public transform
{
public:
    std::string translate(std::string s) override;
};