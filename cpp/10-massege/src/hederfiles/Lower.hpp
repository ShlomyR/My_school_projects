#pragma once

#include "transform.hpp"

class Lower : public transform
{
public:
    std::string translate(std::string s) override;
};