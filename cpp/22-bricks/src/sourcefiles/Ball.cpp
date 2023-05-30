// #include "Ball.hpp"
// #include "Game.hpp"

#include "../hederfiles/Ball.hpp"
#include "../hederfiles/Game.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

void Ball::initBall()
{
    this->m_dx = 3;
    this->m_dy = 3;
    this->m_tBall.loadFromFile(m_path);
}

void Ball::initSprite(sf::RenderTarget* const target)
{
    const sf::FloatRect paddleBound = Game::getInstance()->getPaddle()->getBounds();
    this->isPressed = false;
    this->m_windowBoundWidth = target->getSize().x;
    this->m_windowBoundHeight = target->getSize().y;
    this->m_sBall.setTexture(this->m_tBall);
    this->m_sBall.setPosition(
        paddleBound.left+40,
        paddleBound.top-10
    );
}

void Ball::updateBall()
{
    bool deleted = false;
    int level = Game::getInstance()->getCurrLevel();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->isPressed = true;
    }

    this->m_ballBounds = this->m_sBall.getGlobalBounds();

    this->m_ballBounds.left += this->m_dx;
    sf::FloatRect ballBoundX = sf::Rect<float>(this->m_ballBounds.left, this->m_ballBounds.top,this->m_ballBounds.width,this->m_ballBounds.height);
    for (int i = 0; i < Game::getInstance()->getVecObj()[level]->getN(); i++) {
        if (ballBoundX.intersects(Game::getInstance()->getVecObj()[level]->getSBrick(i).getGlobalBounds())) {
            deleted = true;
            if (deleted) {
                Game::getInstance()->sound.play();
                Game::getInstance()->getVecObj()[level]->deleteBricks(i);
                Game::getInstance()->getInformation()->increaseHealth();
                this->m_dx = -m_dx;
                break;
            }
            break;
        }
    }
    
    this->m_ballBounds.top += this->m_dy;
    sf::FloatRect ballBoundY = sf::Rect<float>(this->m_ballBounds.left, this->m_ballBounds.top,this->m_ballBounds.width,this->m_ballBounds.height);
    for (int i = 0; i < Game::getInstance()->getVecObj()[level]->getN(); i++) {
        if (ballBoundY.intersects(Game::getInstance()->getVecObj()[level]->getSBrick(i).getGlobalBounds())) {
            deleted = true;
            if (deleted) {
                Game::getInstance()->sound.play();
                Game::getInstance()->getVecObj()[level]->deleteBricks(i);
                Game::getInstance()->getInformation()->increaseHealth();
                this->m_dy = -m_dy;
                break;
            }
            break;
        }
    }

    //ball borders
    if (this->m_ballBounds.left <= 0 || this->m_ballBounds.left >= this->m_windowBoundWidth - this->m_ballBounds.width) {
        this->m_dx = -m_dx;
    } else if (this->m_ballBounds.top <= 0 || this->m_ballBounds.top >= this->m_windowBoundHeight - this->m_ballBounds.height) {
        this->m_dy = -m_dy;
        if (!(this->m_ballBounds.top <= 0)) {
            Game::getInstance()->getInformation()->decreaseHealth();
            this->isPressed = false;
        }
    }

    if (this->isPressed) {
        this->m_sBall.setPosition(this->m_ballBounds.left, this->m_ballBounds.top);
    } else {
        this->m_sBall.setPosition(Game::getInstance()->getPaddle()->getBounds().left+40,Game::getInstance()->getPaddle()->getBounds().top-13);
    }
}

void Ball::renderBall(sf::RenderTarget *const target)
{
    target->draw(this->m_sBall);
}

float Ball::getRandomDirection()
{
    return this->m_dy = -(rand() % 8 + 2);
}

sf::FloatRect Ball::getBounds()
{
    return this->m_ballBounds;
}