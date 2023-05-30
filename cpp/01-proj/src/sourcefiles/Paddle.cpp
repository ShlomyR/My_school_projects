#include "../hederfiles/Paddle.hpp"
#include "../hederfiles/GameManager.hpp"

Paddle::Paddle(std::string path)
{
    if (!m_tPaddle.loadFromFile(path)) {
        throw std::runtime_error("File was not loaded!!!");
    }
}

void Paddle::init(std::unique_ptr<sf::RenderWindow> &window)
{
    this->m_sPaddle.setTexture(this->m_tPaddle);
    this->m_sPaddle.setPosition(
        window->getSize().x/2-this->m_sPaddle.getGlobalBounds().width/2, 
        window->getSize().y-this->m_sPaddle.getGlobalBounds().height
    );
}

void Paddle::initSprite(std::unique_ptr<sf::RenderWindow> &)
{
    return;
}

void Paddle::update(std::unique_ptr<sf::RenderWindow> &target)
{
    float s_paddlePosX = this->m_sPaddle.getPosition().x;
    float left = s_paddlePosX - this->m_sPaddle.getScale().x /2.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && left < target->getSize().x - this->m_sPaddle.getGlobalBounds().width) {
        this->m_sPaddle.move(10, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && left > 0) {
        this->m_sPaddle.move(-10, 0);
    }
    

    sf::FloatRect ballBounds = GameManager::getInstance()->getBallObj()->getBounds();
    sf::FloatRect ballBoundX = sf::Rect<float>(ballBounds.left, ballBounds.top,ballBounds.width,ballBounds.height);

    if (ballBoundX.intersects(this->m_sPaddle.getGlobalBounds())) {
        GameManager::getInstance()->getBallObj()->getRandomDirection();

    }
    
}

void Paddle::render(std::unique_ptr<sf::RenderWindow>  &target)
{
    target->draw(this->m_sPaddle);
}

void Paddle::left()
{
    this->m_sPaddle.move(-10, 0);
}

void Paddle::right()
{
    this->m_sPaddle.move(10, 0);
}

const sf::FloatRect Paddle::getBounds() const
{
    return this->m_sPaddle.getGlobalBounds();
}

sf::Sprite &Paddle::getSprite()
{
    return m_sPaddle;
}

const sf::Vector2f &Paddle::getPos() const
{
    return this->m_sPaddle.getPosition();
}
