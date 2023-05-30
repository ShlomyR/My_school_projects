#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "../hederfiles/WindowAdapter.hpp"
#include "../hederfiles/Collision.hpp"
#include "../hederfiles/Ball.hpp"
#include "../hederfiles/Paddle.hpp"
#include "../hederfiles/Border.hpp"
#include "../hederfiles/Brick.hpp"
#include "../hederfiles/GameManager_1.hpp"
#include "../hederfiles/ArrowMovement.hpp"

int main()
{
    std::unique_ptr<WindowAdapter> window = std::make_unique<WindowAdapter>(
        800
        , 600
        , "SFML Pong"
    );
    
    std::unique_ptr<Border> border = std::make_unique<Border>(
        sf::Vector2f(
            795.f
            , 595.f
        )
        , sf::Vector2f(
            window->getSize().x - 797.f
            , window->getSize().y - 597.f
        )
        , sf::Color::Red
    );

    std::shared_ptr<Paddle> paddle = std::make_shared<Paddle>(
        sf::Vector2f(100.f, 10.f)
        , sf::Vector2f(
            window->getSize().x / 2.f - 50
            ,window->getSize().y - 20
        )
        , sf::Color::Blue
    );

    std::unique_ptr<Ball> ball = std::make_unique<Ball>(
        10.f
        , sf::Vector2f(
            window->getSize().x / 2.f 
            , window->getSize().y - 20
        )
        , sf::Color::White
    );

    std::unique_ptr<Brick> brick = std::make_unique<Brick>(
        sf::Vector2f(25.f, 10.f)
        , sf::Vector2f(
            window->getSize().x / 2.f - 50
            ,window->getSize().y - 40
        )
        , sf::Color::Yellow
    );
    std::unique_ptr<ArrowMovement> arrow_movement = std::make_unique<ArrowMovement>(paddle,10);
    //(i+0.5)* 45, (j+4) * 30
    brick->init();

    GameManager::getInstance()->setBall(ball);
    GameManager::getInstance()->setBorder(border);
    GameManager::getInstance()->setPaddle(paddle);
    GameManager::getInstance()->setWindow(window);
    GameManager::getInstance()->setBrick(brick);
    GameManager::getInstance()->setArrowMovement(arrow_movement);
    GameManager::getInstance()->start();

    return 0;
}