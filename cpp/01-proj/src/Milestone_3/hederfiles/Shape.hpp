#pragma once

#include <SFML/Graphics.hpp>
#include "WindowAdapter.hpp"


#include <cmath>
#include <memory>

class Shape
{
public:
    virtual void move(float, float) = 0;
    virtual void setPosition(float, float) = 0;
    virtual void draw(std::unique_ptr<WindowAdapter> &) = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual float getRadius() const = 0;
};