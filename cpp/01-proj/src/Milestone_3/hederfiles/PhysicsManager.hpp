#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Brick.hpp"
#include "Border.hpp"
#include "Paddle.hpp"

class PhysicsManager {
public:
    PhysicsManager();
    void update(float deltaTime, Ball& ball, Paddle& paddle, Brick& brick, Border& border);
private:
    void checkPaddleCollision(Ball& ball, Paddle& paddle);
    void checkBrickCollision(Ball& ball, Brick& brick);
    void checkBorderCollision(Ball& ball, Border& border);
    float m_ballSpeed;
};