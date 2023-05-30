#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "../hederfiles/Ball.hpp"
#include "../hederfiles/Paddle.hpp"
#include "../hederfiles/Border.hpp"
#include "../hederfiles/Brick.hpp"
#include "../hederfiles/WindowManager.hpp"
#include "../hederfiles/GameManager.hpp"
#include "../hederfiles/InputManager.hpp"

int main()
{
    WindowManager window(sf::Vector2u(800,600) , "SFML Pong");
    InputManager input_manager;
    Border border(sf::Vector2f(795.f, 595.f), sf::Vector2f(window.getSize().x - 797.f, window.getSize().y - 597.f), sf::Color::Red);
    Paddle paddle(sf::Vector2f(100.f, 10.f), sf::Vector2f(window.getSize().x / 2.f - 50,window.getSize().y - 20), sf::Color::Blue);
    Ball ball(10.f, sf::Vector2f(window.getSize().x / 2.f , window.getSize().y - 20), sf::Color::White);
    Brick brick(sf::Vector2f(25.f, 10.f), sf::Vector2f(window.getSize().x / 2.f - 50,window.getSize().y - 40), sf::Color::Yellow);
    
    brick.init();

    GameManager game(window, input_manager, ball, brick, paddle, border);
    game.run();

    return 0;
}