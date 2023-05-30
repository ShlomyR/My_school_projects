#pragma once

#include <SFML/Graphics.hpp>

#include "Paddle.hpp"

#include <memory>

class ArrowMovement {
public:
    ArrowMovement(std::shared_ptr<Paddle> &,float);
    // void moveUp();
    // void moveDown();
    void moveLeft();
    void moveRight();

private:
    std::shared_ptr<Paddle> m_rectangle;
    float m_moveSpeed;
};
