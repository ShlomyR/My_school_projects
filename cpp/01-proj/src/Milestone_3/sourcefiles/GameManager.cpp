#include <iostream>

#include "../hederfiles/GameManager_1.hpp"

GameManager *GameManager::getInstance()
{
    static GameManager m_instance;
    return &m_instance;
}

void GameManager::start()
{
    init();
    m_ball->setDirection(sf::Vector2f(std::rand() % 200 - 100, std::rand() % 200 - 100));
    // InputHandler inputHandler(m_window);
    // GameLogic gameLogic(m_deltaTime, m_ballSpeed, m_ball, m_brick, m_paddle, m_arrow_movement, m_collision);
    // Renderer renderer(m_window, m_ball, m_brick, m_border, m_paddle);
    sf::Event m_event;
    sf::Clock m_clock;
    while (m_window->isOpen()) {
        m_deltaTime = 0.03;
        m_handler->handleEvent(m_event);
        m_handler->logics(this->m_deltaTime,this->m_ballSpeed);
        m_window->clear();
        m_handler->draw();
        m_window->display();
    }
}

void GameManager::pause()
{
    bool paused = true;
    while (paused) {
        sf::Event event;
        while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                paused = !paused;
            }
        }
    }
}

void GameManager::reset()
{
    m_brick->init();
    m_paddle->setIsPressed(false);
    m_ball->setPosition(m_paddle->getShape()->getGlobalBounds().left+50,m_paddle->getShape()->getGlobalBounds().top-13);
}

void GameManager::init()
{
    m_deltaTime = 0.f;
    m_ballSpeed = 200.f;
}

std::unique_ptr<Ball> &GameManager::getBall()
{
    return m_ball;
}

std::unique_ptr<Brick> &GameManager::getBrick()
{
    return m_brick;
}

std::unique_ptr<Border> &GameManager::getBorder()
{
    return m_border;
}

std::shared_ptr<Paddle> &GameManager::getPaddle()
{
    return m_paddle;
}

std::unique_ptr<ArrowMovement> &GameManager::getArrowMovement()
{
    return m_arrow_movement;
}

std::unique_ptr<Collision> &GameManager::getCollision()
{
    return m_collision;
}

std::unique_ptr<WindowAdapter> &GameManager::getWindow()
{
    return m_window;
}

void GameManager::setBall(std::unique_ptr<Ball> &circle)
{
    this->m_ball = std::move(circle);
}

void GameManager::setBorder(std::unique_ptr<Border> &rectangle)
{
    this->m_border = std::move(rectangle);
}

void GameManager::setBrick(std::unique_ptr<Brick> &brick)
{
    this->m_brick = std::move(brick);
}

void GameManager::setPaddle(std::shared_ptr<Paddle> &paddle)
{
    this->m_paddle = paddle;   
}

void GameManager::setArrowMovement(std::unique_ptr<ArrowMovement> &arrow_movement)
{
    this->m_arrow_movement = std::move(arrow_movement);
}

void GameManager::setCollision(std::unique_ptr<Collision> &collision)
{
    this->m_collision = std::move(collision);
}

void GameManager::setWindow(std::unique_ptr<WindowAdapter> &window)
{
    this->m_window = std::move(window);
}