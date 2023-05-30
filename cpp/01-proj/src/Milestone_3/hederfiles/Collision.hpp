#pragma once

#include <SFML/Graphics.hpp>

#include "Paddle.hpp"
#include "Border.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "WindowAdapter.hpp"

class Collision
{
public:
    static bool checkCircleRectangleCollision(const sf::CircleShape &, const sf::RectangleShape &);
    static bool checkCircleCircleCollision(const sf::CircleShape &, const sf::CircleShape &);
    void checkBallCollisions(
        std::unique_ptr<Ball> &
        , std::unique_ptr<Border> &
        , std::shared_ptr<Paddle> &
        , std::unique_ptr<Brick> &
        , std::unique_ptr<WindowAdapter> &
    );
};