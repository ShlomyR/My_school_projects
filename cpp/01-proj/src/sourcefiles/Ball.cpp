#include "../hederfiles/Ball.hpp"
#include "../hederfiles/GameManager.hpp"
// #include "../hederfiles/BallManager.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

void Ball::init(std::unique_ptr<sf::RenderWindow> &)
{
    m_ball_manager->init();
    m_ball_manager->m_speed = 1.f;
    this->m_tBall.loadFromFile(m_path);
}

void Ball::initSprite(std::unique_ptr<sf::RenderWindow> &target)
{
    const sf::FloatRect paddleBound = GameManager::getInstance()->getPaddleObj()->getBounds();
    m_ball_manager->m_windowBoundWidth = target->getSize().x;
    m_ball_manager->m_windowBoundHeight = target->getSize().y;
    this->m_sBall.setTexture(this->m_tBall);
    this->m_sBall.setPosition(
        paddleBound.left+40,
        paddleBound.top-10
    );
}

void Ball::update(std::unique_ptr<sf::RenderWindow> &)
{
    //int level = GameManager::getInstance()->getCurrLevel();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_ball_manager->isPressed = true;
    }
    // ball Collision With a Brick
    this->m_ballBounds = this->m_sBall.getGlobalBounds();
    m_border->ballCollideWithBrick(
        GameManager::getInstance()->getBricksObj()
        ,m_ball_manager
        ,m_ballBounds
    );
    // ball borders
    m_border->windowBorderDetection(
        this->m_ball_manager
        ,this->m_ballBounds
    );
    // ball set position
    if (m_ball_manager->isPressed) {
        this->m_sBall.setPosition(
            this->m_ballBounds.left
            , this->m_ballBounds.top
        );
    } else {
        this->m_sBall.setPosition(
            GameManager::getInstance()->getPaddleObj()->getBounds().left+40
            ,GameManager::getInstance()->getPaddleObj()->getBounds().top-13
        );
    }
}

void Ball::render(std::unique_ptr<sf::RenderWindow> &target)
{
    target->draw(this->m_sBall);
}

float Ball::getRandomDirection()
{
    return m_ball_manager->m_dy = -(rand() % 8 + 2);
}

sf::FloatRect Ball::getBounds()
{
    return this->m_ballBounds;
}