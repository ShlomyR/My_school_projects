#include "../hederfiles/Brick.hpp"

Brick::Brick(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color)
:    m_shape(std::make_unique<sf::RectangleShape>(size))
{
    m_shape->setFillColor(sf::Color::Green);
    m_shape->setOutlineColor(color);
    m_shape->setOutlineThickness(1.f);
    setPosition(position.x, position.y);
}

void Brick::move(float x, float y)
{
    m_shape->move(x, y);
}

void Brick::setPosition(float x, float y)
{
    m_shape->setPosition(x, y);
}

void Brick::draw(sf::RenderWindow &window)
{
    for (auto &i : m_bricks) {
        window.draw(i);
    }
}

sf::Vector2f Brick::getPosition() const
{
    return m_shape->getPosition();
}

float Brick::getRadius() const
{
    return 0.f;
}

std::vector<sf::RectangleShape> Brick::getVecBricks()
{
    return m_bricks;
}

std::unique_ptr<sf::RectangleShape> &Brick::getShape()
{
    return m_shape;
}

void Brick::pushToVec(sf::RectangleShape rec_shape)
{
    m_bricks.push_back(rec_shape);
}

void Brick::createRowOfBricks()
{

}

void Brick::init()
{
    sf::Color color;
    m_bricks.clear(); // clear the vector of bricks
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            if (j == 0) {
                color = sf::Color::Green; 
            } if (j == 1) {
               color = sf::Color::Blue;
            } if (j == 2) {
               color = sf::Color::Red;
            }
            
            
            bool isHit = false;
            for (auto& hitBrick : m_hitBricks) {
                if (hitBrick.x == i && hitBrick.y == j) {
                    isHit = true;
                    break;
                }
            }
            if (!isHit) {
                std::unique_ptr<sf::RectangleShape> brick = std::make_unique<sf::RectangleShape>(sf::Vector2f(25.f, 10.f));
                brick->setFillColor(color);
                brick->setPosition((i + 2.3) * 80, (j + 3) * 40);
                brick->setScale(sf::Vector2f(3.f, 3.5f));
                m_bricks.push_back(*brick);
            }
        }
    }
    m_hitBricks.clear(); // clear the vector of hit bricks
}

bool Brick::getIsDestroyed() const
{
    return m_isDestroyed;
}

void Brick::setIsDestroyed(bool destroyed)
{
    this->m_isDestroyed = destroyed;
}

void Brick::deleteBrick(int i)
{
    this->m_bricks.erase(this->m_bricks.begin() + i);
}

sf::RectangleShape Brick::getBrick(int i)
{
    return m_bricks[i];   
}

bool Brick::isEmpty()
{
    if (m_bricks.empty()) {
        return true;
    } else {
        return false;
    }
}
