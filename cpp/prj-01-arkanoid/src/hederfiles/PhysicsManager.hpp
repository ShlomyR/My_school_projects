#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Brick.hpp"
#include "Border.hpp"
#include "Paddle.hpp"
#include "GameState.hpp"

class PhysicsManager {
public:
    PhysicsManager();
        void update(float deltaTime
        , Ball& ball
        , Paddle& paddle
        , Brick& brick
        , Border& border
        , GameState& game_state
    );
private:
    void checkPaddleCollision(Ball& ball, Paddle& paddle);
    void checkBrickCollision(Ball& ball, Brick& brick,GameState& game_state);
    void checkBorderCollision(Ball& ball, Border& border);
    void checkPaddleBorderCollision(Paddle& paddle, Border& border);
    float m_ballSpeed;
};