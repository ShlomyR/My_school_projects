// #include "Paddle.hpp"
// #include "Game.hpp"


#include "../hederfiles/Game.hpp"
#include "../hederfiles/Paddle.hpp"



Paddle::Paddle(std::string path)
{
    this->m_tPaddle.loadFromFile(path);
}

void Paddle::initSprite(sf::RenderTarget* const target)
{
    this->m_sPaddle.setTexture(this->m_tPaddle);
    this->m_sPaddle.setPosition(
        target->getSize().x/2-this->m_sPaddle.getGlobalBounds().width/2, 
        target->getSize().y-this->m_sPaddle.getGlobalBounds().height
    );
}

void Paddle::renderPaddle(sf::RenderTarget* const target)
{
    target->draw(this->m_sPaddle);
}

void Paddle::updatePaddle(sf::RenderTarget* const target)
{
    float s_paddlePosX = this->m_sPaddle.getPosition().x;
    float left = s_paddlePosX - this->m_sPaddle.getScale().x /2.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && left < target->getSize().x - this->m_sPaddle.getGlobalBounds().width) {
        this->m_sPaddle.move(10, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && left > 0) {
        this->m_sPaddle.move(-10, 0);
    }
    

    sf::FloatRect ballBounds = Game::getInstance()->getBall()->getBounds();
    sf::FloatRect ballBoundX = sf::Rect<float>(ballBounds.left, ballBounds.top,ballBounds.width,ballBounds.height);

    if (ballBoundX.intersects(this->m_sPaddle.getGlobalBounds())) {
        Game::getInstance()->getBall()->getRandomDirection();

    }
}

const sf::Vector2f& Paddle::getPos() const
{
    return this->m_sPaddle.getPosition();
}

const sf::FloatRect Paddle::getBounds() const
{
    return this->m_sPaddle.getGlobalBounds();
}

sf::Sprite& Paddle::getSprite()
{
    return this->m_sPaddle;
}